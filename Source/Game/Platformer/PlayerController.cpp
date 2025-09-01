#include "../../Game/GamePCH.h"
#include "EnginePCH.h"
#include "PlayerController.h"

namespace parabellum{

FACTORY_REGISTER(PlayerController)

void PlayerController::Start()
{
	m_rb = owner->getComponent<RigidBody>(); //returns a null object. fix por favor

}

void PlayerController::Update(float dt)
{
	float thrust = 0;

	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_A)) thrust = -1;
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_D)) thrust = 1;
	vec2 direction{ 1,0 };
	//vec2 force = direction.Rotate(math::degrees_to_radius(owner->m_transform.rotation)) * thrust * speed;

	if (thrust != 0) {
		m_rb->ApplyForce(vec2{ 1,0 } * thrust * 10000);
	}
	if (getEngine().getInputSys().getKeyPressed(SDL_SCANCODE_SPACE)) {
		m_rb->ApplyForce(vec2{ 0,-1 } * 1000000);

	}

	// something wrong here, perhaps?
	//velocity += force * dt;
	//auto rb = owner->getComponent<parabellum::RigidBody>();

	//m_rb->setVelocity(force);

}

void PlayerController::OnCollision(parabellum::Actor* other)
{

}

void PlayerController::Read(const json::value_t& value)
{
	Object::Read(value);
	JSON_READ(value, speed);
	JSON_READ(value, maxSpeed);
	JSON_READ(value, jump);

}
}
