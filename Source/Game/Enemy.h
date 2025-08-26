#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Framework/Component.h"
#include "Core/Factory.h"


namespace parabellum{
class Enemy : public Component, public ICollidable {
public:

	CLASS_PROTOTYPE(Enemy)
	float speed = 200;
	Enemy() = default;


	void Start() override;
	void Update(float dt) override;
	void Read(const json::value_t& value) override;
	RigidBody* m_rb;
private:




	// Inherited via Actor
	void OnCollision(class Actor* other) override ;


};
}