#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"
#include "Math/Vector2.h"
#include "Renderer/Renderer.h"
#include "GameData.h"
#include "Bullet.h"
#include <iostream>
#include "Framework/Scene.h"
#include "SpaceGame.h"
#include "Framework/Game.h"


FACTORY_REGISTER(Player)

void Player::Start()
{
	m_rb = owner->getComponent<RigidBody>();
}

void Player::Update(float dt)
{


	float rotate = 0;
	float thrust = 0;

	//rotate

	vec2 mousepos = getEngine().getInputSys().getMousePos();
	float angle = (mousepos - owner->m_transform.position).Angle();
	m_rb->ApplyTorque(math::degrees_to_radius(angle)); //HELP!!!!

	//use mouse position relative to the actual player's position
	owner->m_transform.rotation = math::radius_to_degrees(angle); // supposed to track mouse position to rotate



	//thrust
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_S)) thrust = -1;
	vec2 direction{ 1,0 };
	vec2 force = direction.Rotate(math::degrees_to_radius(owner->m_transform.rotation)) * thrust * speed;


	// something wrong here, perhaps?
	//velocity += force * dt;
	//auto rb = owner->getComponent<parabellum::RigidBody>();
	
	m_rb->setVelocity(force);
	



	//check button to fire bullet!


	if (parabellum::getEngine().getInputSys().GetMouseButtonPressed(InputSystem::MouseButton::MOUSE_LEFT)) {
		Transform tf(this->owner->m_transform.position, this->owner->m_transform.rotation, 2.0f);
		auto bullet = Instantiate("bullet", tf);

		owner->m_scene->AddActor(std::move(bullet));

		//owner->m_scene->GetActorByName("bullet")->Update(dt); // absolute guess on how to get this working.
	}
	
}

void Player::OnCollision(parabellum::Actor* other)
{
	if (owner->tag != other->tag) {
		owner->stillAlive = false;
		EVENT_NOTIFY(player_dead);
		//EventManager::Instance().Notify(Event{ "player_dead", true });

		dynamic_cast<SpaceGame*>(owner->m_scene->getGame())->onPlayerDead();
		//getEngine().GTFO();
		//exit(1);
	}
}

void Player::Read(const json::value_t& value)
{
	Object::Read(value); //reads in name and if its active

	JSON_READ(value, speed);
	JSON_READ(value, rotationRate);


}
