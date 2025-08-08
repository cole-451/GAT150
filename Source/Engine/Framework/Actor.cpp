#include "Actor.h"
#include "../Renderer/Renderer.h"

void parabellum::Actor::Update(float dt)
{

	//check to see if actor is dead
	if (!stillAlive) { return; }

	if (lifespan != 0) {
		lifespan -= dt;
		if (lifespan <= 0) {
			stillAlive = false;
		}
	}

	m_transform.position += velocity * dt;
	//velocity *= 0; the overloads are const and DO NOT like this

}

void parabellum::Actor::Draw(Renderer& renderer)
{
	renderer.DrawTexture(m_texture.get(), m_transform.position.x, m_transform.position.y, m_transform.rotation, m_transform.scale);
	//m_model->Draw(renderer, m_transform);
}

/// <summary>
/// Returns the effective radius of the actor based on its texture size, scale, and a scaling factor.
/// </summary>
/// <returns>The computed radius of the actor. Returns 0 if no texture is assigned.</returns>
float parabellum::Actor::getRadius()
{
	return (m_texture) ? (m_texture->GetSize().length() ) * m_transform.scale : 0.0f; // check up on this
}
