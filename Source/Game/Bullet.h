#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Framework/Component.h"


class Bullet : public parabellum::Component {
public:

	float speed = 200;
	float rotationRate = 0;
	Bullet() = default;
	//Bullet(const Transform& transform) : // something wrong with this call.
	//	Actor{ transform }
	//{
	//}

	void Update(float dt) override;
private:

	// Inherited via Actor
	void onCollision(parabellum::Actor* other);
};