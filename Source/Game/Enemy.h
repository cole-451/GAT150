#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"




class Enemy : public parabellum::Actor {
public:

	float speed = 200;
	Enemy() = default;
	Enemy(const Transform& transform, parabellum::res_t<parabellum::Texture> texture) :
		Actor{ transform, texture }
	{
	}

	void Update(float dt) override;
private:




	// Inherited via Actor
	void onCollision(Actor* other) override;

};