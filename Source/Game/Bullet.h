#pragma once
#include "Framework/Actor.h"

class Bullet : public parabellum::Actor {
public:

	float speed = 200;
	float rotationRate = 0;
	Bullet() = default;
	Bullet(const Transform& transform, class std::shared_ptr<parabellum::Model> model) :
		Actor{ transform, model }
	{
	}

	void Update(float dt) override;
private:

	// Inherited via Actor
	void onCollision(Actor* other) override;
};