#include "Bullet.h"
#include "Engine.h"
#include "Player.h"



// When you get Enemy.cpp done, paste that shit here.

void Bullet::Update(float dt)
{
	vec2 force = vec2{ 1,0 }.Rotate(math::degrees_to_radius(m_transform.rotation)) * speed * dt;
	velocity = force;

	//if i had the wrap command working, id put it here
	m_transform.position.x = parabellum::math::Wrap(m_transform.position.x, 0.0f, 1280.0f);
	m_transform.position.y = parabellum::math::Wrap(m_transform.position.y, 0.0f, 1024.0f);

	Actor::Update(dt);
}

void Bullet::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
		//m_scene->getGame()->addPoints(200);

	}
	
}
