#pragma once

#include "Framework/Actor.h"
#include "Renderer/Texture.h"


namespace parabellum {

class PlayerController : public parabellum::Component, public ICollidable {
public:
	CLASS_PROTOTYPE(PlayerController) // clones an object of the player. Macro is in Object.h
		PlayerController() = default;


	void Start() override;
	void Update(float dt) override;
	float speed{ 0 };
	float maxSpeed{ 0 };
	float jump{ 0 };
	RigidBody* m_rb{ nullptr };

private:



	// Inherited via Actor
	void OnCollision(class parabellum::Actor* other) override;

	void Read(const json::value_t& value) override;

};
}

