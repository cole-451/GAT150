#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "Components/RendererComponent.h"

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
	renderer.DrawTexture(m_texture.get(), m_transform.position.x, m_transform.position.y, m_transform.rotation, m_transform.scale);
}

/// <summary>
/// Returns the effective radius of the actor based on its texture size, scale, and a scaling factor.
/// </summary>
/// <returns>The computed radius of the actor. Returns 0 if no texture is assigned.</returns>
/// 
/// 
float parabellum::Actor::getRadius()
{
	return (m_texture) ? (m_texture->GetSize().length() * 0.5f ) * m_transform.scale * 0.5f : 0; // check up on this
}

void parabellum::Actor::addComponent(std::unique_ptr<Component> component)
{
	component->owner = this;
	m_components.push_back(std::move(component));
}


