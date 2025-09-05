#include "../Game/GamePCH.h"
#include "EnemyController.h"

namespace parabellum {

	FACTORY_REGISTER(EnemyController)


void EnemyController::Start()
{
	m_rb = owner->getComponent<RigidBody>(); 


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

	OnOutOfBounds(); //check if you're out of bounds
}

void EnemyController::OnCollision(parabellum::Actor* other)
{
}

void EnemyController::OnOutOfBounds() // maybe make a bool?
{
	if (owner->m_transform.position.y > 1000) {
		owner->Destroyed();
		owner->stillAlive = false;
		//add points to HUD
		EventManager::Instance().Notify(Event{ "add_points", 100 });
		getEngine().getAudioSys().playSound("crate_destroyed");
		//return true;
		
	}
}

void EnemyController::Read(const json::value_t& value)
{
	Object::Read(value);
	JSON_READ(value, speed);
	JSON_READ(value, maxSpeed);
	JSON_READ(value, jump);
}
}
