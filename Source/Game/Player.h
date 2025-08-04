#pragma once
#include "Framework/Actor.h"

using namespace parabellum;


class Player : public parabellum::Actor {
public:
	Player() = default;
	Player(const Transform& transform, class std::shared_ptr<parabellum::Model> model) :
		Actor{transform, model}
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