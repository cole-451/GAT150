#include "Enemy.h"
#include "Engine.h"


void Enemy::Update(float dt)
{

	Actor* player = m_scene->GetActorByName("player");
	if (player) {
	vec2 direction{ 0,0 };
	direction = player->m_transform.position - m_transform.position;
	direction = direction.Normalized();
	m_transform.rotation = parabellum::math::radius_to_degrees(direction.Angle());

	}
	vec2 force = vec2{ 1,0 }.Rotate(parabellum::math::degrees_to_radius(m_transform.rotation)) * dt;
	//velocity = force;
	getComponent<parabellum::RigidBody>()->velocity += force * dt;
	auto rb = getComponent<parabellum::RigidBody>();
	if (rb) {
		rb->velocity += force * dt;
	}
	Actor::Update(dt);
}

void Enemy::onCollision(Actor* other)
{
	if (tag != other->tag) {
		stillAlive = false;
		m_scene->getGame()->addPoints(100);
		parabellum::Particle particle;

		particle.position = m_transform.position;
		//transform pos x and y stuff split into two seperate lines???
		// 
		//particle.velocity = parabellum::random::onUnitCircle() * parabellum::random::getReal(10.0f, 20.0f);
		particle.color = vec3{ 1, 1, 1 };
		particle.lifespan = 2;

		parabellum::getEngine().getPS().addParticle(particle);

	}
}
