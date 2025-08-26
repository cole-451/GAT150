#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "Components/RendererComponent.h"

namespace parabellum {
	FACTORY_REGISTER(Actor)

		Actor::Actor(const Actor& other) :
		Object{ other },
		tag{ other.tag },
		lifespan{ other.lifespan },
		m_transform{other.m_transform}

	{
		for (auto& component : other.m_components) {
			auto clone = std::unique_ptr<Component> (dynamic_cast<Component*> (component->Clone().release()));
			addComponent(std::move(clone));
		}
	}


	void parabellum::Actor::Update(float dt)
	{

		//check to see if actor is dead
		if (!stillAlive) { return; }

		if (lifespan > 0) {
			lifespan -= dt;
			if (lifespan <= 0) {
				stillAlive = false;
				return;
			}
		}

		//update all components
		for (auto& component : m_components) {
			if (component->active) {
				component->Update(dt);
			}
		}


	}

	void parabellum::Actor::Draw(Renderer& renderer)
	{
		for (auto& component : m_components) {
			if (component->active) {
				auto rendererComponent = dynamic_cast<RendererComponent*>(component.get());
				if (rendererComponent) {
					rendererComponent->draw(renderer);

				}
			}
		}
		//renderer.DrawTexture(m_texture.get(), m_transform.position.x, m_transform.position.y, m_transform.rotation, m_transform.scale);
	}

	/// <summary>
	/// Returns the effective radius of the actor based on its texture size, scale, and a scaling factor.
	/// </summary>
	/// <returns>The computed radius of the actor. Returns 0 if no texture is assigned.</returns>
	/// 
	/// 


	void Actor::OnCollision(Actor* other)
	{
		auto collidables = getComponents<ICollidable>();
		for (auto& collideable : collidables) {
			collideable->OnCollision(other);
		}
	}

	void parabellum::Actor::addComponent(std::unique_ptr<Component> component)
	{
		component->owner = this;
		m_components.push_back(std::move(component));
	}
	void Actor::Read(const json::value_t& value)
	{
		if (JSON_HAS(value, name) && JSON_HAS(value, active)) {
			Object::Read(value); // supposed to read the values that Object shares.
		}
		JSON_READ(value, persistent);
		JSON_READ(value, tag);

		if (JSON_HAS(value, lifespan)) { // possibly skip over in case it does not have a lifespan
			JSON_READ(value, lifespan);
		}

		if (JSON_HAS(value, m_transform)) { m_transform.Read(JSON_GET(value, m_transform)); }

		//read components
		if (JSON_HAS(value, components)) {

			for (auto& componentValue : JSON_GET(value, components).GetArray()) {
				std::string type;
				JSON_READ(componentValue, type);
				auto component = Factory::Instance().Create<Component>(type);

				if (!component) { // if there's no component, shoot out an error
					Logger::Error("Could not create pointer for component {}", type);
					return;
				}
				component->Read(componentValue); //gets a nullptr here

				addComponent(std::move(component));
			}
		}

	}
	void Actor::Start()
	{
		for (auto& component : m_components) {
			if (component->active) {
				component->Start();
			}
		}

	}
	void Actor::Destroyed()
	{
		for (auto& component : m_components) {
			if (component->active) {
				component->Destroyed();
			}
		}
	}
}


