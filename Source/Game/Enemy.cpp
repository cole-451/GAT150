#include "../Game/GamePCH.h"
#include "Enemy.h"
#include "Engine.h"


namespace parabellum {

FACTORY_REGISTER(Enemy)
void Enemy::Update(float dt)
{
	/*
	Actor* player = owner->m_scene->GetActorByName("player");
	if (player) {
	vec2 direction{ 0,0 };
	direction = player->m_transform.position - owner->m_transform.position;
	direction = direction.Normalized();
	owner->m_transform.rotation = parabellum::math::radius_to_degrees(direction.Angle());

	}
	vec2 force = vec2{ 1,0 }.Rotate(parabellum::math::degrees_to_radius(owner->m_transform.rotation)) * dt;
	//velocity = force;
	owner->getComponent<parabellum::RigidBody>()->velocity += force * dt;
	auto rb = owner->getComponent<parabellum::RigidBody>();
	if (rb) {
		rb->velocity += force * dt;
	}
	owner->Update(dt);
	*/
}

void Enemy::Read(const json::value_t& value)
{
	Object::Read(value);
	JSON_READ(value, speed);
}

void Enemy::onCollision(parabellum::Actor* other)
{
	if (owner->tag != other->tag) {
		owner->stillAlive = false;
		owner->m_scene->getGame()->addPoints(100);
		parabellum::Particle particle;

		particle.position = owner->m_transform.position;
		//transform pos x and y stuff split into two seperate lines???
		// 
		//particle.velocity = parabellum::random::onUnitCircle() * parabellum::random::getReal(10.0f, 20.0f);
		particle.color = vec3{ 1, 1, 1 };
		particle.lifespan = 2;

		parabellum::getEngine().getPS().addParticle(particle);

	}
}
}
