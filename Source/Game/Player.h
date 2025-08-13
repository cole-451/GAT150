#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"


using namespace parabellum;


class Player : public parabellum::Actor {
public:
	Player() = default;
	Player(const Transform& transform) :
		Actor{transform}
	{
	}

	//void Draw(Renderer& renderer) override;



	void Update(float dt) override;
	float speed{ 0 };
	float rotationRate{ 0 };
private:



	// Inherited via Actor
	void onCollision(Actor* other) override;

};