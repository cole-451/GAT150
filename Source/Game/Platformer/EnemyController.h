#pragma once 
// HELP!!!!!!!

#include "Framework/Actor.h"
#include "Renderer/Texture.h"


namespace parabellum {

class EnemyController : public parabellum::Component, public ICollidable {
public:
	CLASS_PROTOTYPE(EnemyController) // clones an object of the player. Macro is in Object.h
		EnemyController() = default;


	void Start() override;
	void Update(float dt) override;
	float speed{ 0 };
	float maxSpeed{ 0 };
	float jump{ 0 };
	RigidBody* m_rb;

private:



	// Inherited via Actor
	void OnCollision(class parabellum::Actor* other) override;

	void Read(const json::value_t& value) override;

};
}