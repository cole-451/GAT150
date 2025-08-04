#include "Actor.h"
#include "../Renderer/Model.h"

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
	m_model->Draw(renderer, m_transform);
}

float parabellum::Actor::getRadius()
{

	return (m_model) ? m_model->getRadius() : 0;
}
