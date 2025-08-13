#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"

class Bullet : public parabellum::Actor {
public:

	float speed = 200;
	float rotationRate = 0;
	Bullet() = default;
	Bullet(const Transform& transform) : // something wrong with this call.
		Actor{ transform }
	{
	}

	void Update(float dt) override;
private:

	// Inherited via Actor
	void onCollision(Actor* other) override;
};