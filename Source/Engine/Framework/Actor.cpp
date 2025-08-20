#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "Components/RendererComponent.h"

namespace parabellum {
	FACTORY_REGISTER(Actor)

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


void parabellum::Actor::addComponent(std::unique_ptr<Component> component)
{
	component->owner = this;
	m_components.push_back(std::move(component));
}
void Actor::Read(const json::value_t& value)
{
	Object::Read(value); // supposed to read the values that Object shares.

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
			if (!component) {
				Logger::Error("Could not create pointer for component {}", type);
				return;
			}
			component->Read(componentValue); //gets a nullptr here

			addComponent(std::move(component));
		}
	}

}
}


