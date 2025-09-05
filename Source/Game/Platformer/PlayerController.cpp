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

	if (thrust != 0) {
		m_rb->ApplyForce(vec2{ 1,0 } * thrust * 1000);
	}
	if (getEngine().getInputSys().getKeyPressed(SDL_SCANCODE_SPACE)) {
		m_rb->ApplyForce(vec2{ 0,-1 } * 100000);

	}
	auto spriterenderer = owner->getComponent<SpriteRenderer>();
	if (spriterenderer && thrust > 0) {
		spriterenderer->flipH = true;
	}
	else if (spriterenderer && thrust < 0) {
		spriterenderer->flipH = false;
	}


}

void PlayerController::OnCollision(parabellum::Actor* other)
{
	//Logger::Debug("bro is touching: ", other->name);

}

void PlayerController::Read(const json::value_t& value)
{
	Object::Read(value);
	JSON_READ(value, speed);
	JSON_READ(value, maxSpeed);
	JSON_READ(value, jump);

}
}
