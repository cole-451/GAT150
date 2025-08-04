#pragma once
#include "Framework/Actor.h"


class Enemy : public parabellum::Actor {
public:

	float speed = 200;
	Enemy() = default;
	Enemy(const Transform& transform, class std::shared_ptr<parabellum::Model> model) :
		Actor{ transform, model }
	{
	}

	void Update(float dt) override;
private:




	// Inherited via Actor
	void onCollision(Actor* other) override;

};