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

void Player::Update(float dt)
{
	/*

	float rotate = 0;
	float thrust = 0;

	//rotate

	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_A)) {
		rotate += -1;
	}
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_D)) {
		rotate += 1;
	}
	vec2 mousepos = getEngine().getInputSys().getMousePos();
	float angle = (mousepos - owner->m_transform.position).Angle();
	//use mouse position relative to the actual player's position
	owner->m_transform.rotation = math::radius_to_degrees(angle); // supposed to track mouse position to rotate
	//rotation works, but sprite is not updating
	//std::cout << m_transform.rotation << std::endl;
		//owner->m_transform.rotation += (rotate * rotationRate) * dt;

	//thrust
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_W)) thrust = 1;
	if (parabellum::getEngine().getInputSys().getKeyDown(SDL_SCANCODE_S)) thrust = -1;
	vec2 direction{ 1,0 };
	vec2 force = direction.Rotate(math::degrees_to_radius(owner->m_transform.rotation)) * thrust * speed;
	// something wrong here, perhaps?
	//velocity += force * dt;
	auto rb = owner->getComponent<parabellum::RigidBody>();
	if (rb) {
		rb->velocity += force * dt;
	}




	//check button to fire bullet!

	if (parabellum::getEngine().getInputSys().GetMouseButtonPressed(InputSystem::MouseButton::MOUSE_LEFT)) {
		getEngine().getAudioSys().playSound("shoot");

		getEngine().getAudioSys().playSound(*Resources().Get<AudioClip>(("bass.wav"), getEngine().getAudioSys()).get());


		//auto model = Resources().Get<Texture>("bullet.png", parabellum::getEngine().getRenderer());

		//TODO: replace textures with calls to add resources

		Transform tf(this->owner->m_transform.position, this->owner->m_transform.rotation, 2.0f);
		auto bullet = std::make_unique<Actor>(tf);
		bullet->name = "Bullet";
		bullet->tag = "player";
		bullet->speed = 9999999;
		bullet->lifespan = 2.0f;

		//components
		auto spriteRenderer = std::make_unique<parabellum::SpriteRenderer>();
		spriteRenderer->textureName = "bullet.png";
		std::unique_ptr<parabellum::RigidBody> rb = std::make_unique<parabellum::RigidBody>();
		bullet->addComponent(std::move(rb));

		bullet->addComponent(std::move(spriteRenderer));
		auto collider = std::make_unique<CircleCollide2D>();
		collider->radius = 60;
		bullet->addComponent(std::move(collider));
		owner->m_scene->AddActor(std::move(bullet));





	}

	//ADDITIONAL: later, we can make some homing rockets or a ray that can make enemies join us
	owner->m_transform.position.x = parabellum::math::Wrap(owner->m_transform.position.x, 0.0f, 1280.0f);
	owner->m_transform.position.y = parabellum::math::Wrap(owner->m_transform.position.y, 0.0f, 1024.0f);

	owner->Update(dt);
	*/
}

void Player::onCollision(parabellum::Actor* other)
{
	if (owner->tag != other->tag) {
		/*if (m_scene->getGame()->getLives() > 0) {
			m_scene->getGame()->setLives(m_scene->getGame()->getLives() - 1);
			return;
		}*/
		owner->stillAlive = false;

		dynamic_cast<SpaceGame*>(owner->m_scene->getGame())->onPlayerDead();
		//getEngine().GTFO();
		//exit(1);
	}
}
