#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"


using namespace parabellum;


class Player : public parabellum::Component, public ICollidable {
public:
	CLASS_PROTOTYPE(Player) // clones an object of the player. Macro is in Object.h
	Player() = default;



	void Update(float dt) override;
	float speed{ 0 };
	float rotationRate{ 0 };
	RigidBody* m_rb;

private:



	// Inherited via Actor
	void OnCollision(class parabellum::Actor* other) override;

	void Read(const json::value_t& value) override;

};