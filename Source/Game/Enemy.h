#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Framework/Component.h"




class Enemy : public parabellum::Actor {
public:

	float speed = 200;
	Enemy() = default;
	Enemy(const Transform& transform) : // also something wrong with this call
		Actor{ transform }
	{
	}

	void Update(float dt) override;
private:




	// Inherited via Actor
	void onCollision(Actor* other) override;

};