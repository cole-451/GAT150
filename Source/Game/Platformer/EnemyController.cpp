#include "EnginePCH.h"
#include "EnemyController.h"

void EnemyController::Start()
{
	m_rb = owner->getComponent<RigidBody>(); //returns a null object. fix por favor

}

void EnemyController::Update(float dt)
{
	float dir = 0;
	auto player = owner->m_scene->GetActorByName<Actor>("player");
	if (player) {
		if (player->m_transform.position.x < owner->m_transform.position.x) dir = -1;
		else dir = 1;
	}

	if (dir != 0) {
		m_rb->ApplyForce(vec2{ 1, 0 } *dir * 500);
	}
}

void EnemyController::OnCollision(parabellum::Actor* other)
{
}

void EnemyController::Read(const json::value_t& value)
{
	Object::Read(value);
	JSON_READ(value, speed);
	JSON_READ(value, maxSpeed);
	JSON_READ(value, jump);
}
