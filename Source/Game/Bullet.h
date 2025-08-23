#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Framework/Component.h"

namespace parabellum {

class Bullet : public parabellum::Component {
public:

	CLASS_PROTOTYPE(Bullet)

	float speed = 200;
	float rotationRate = 0;
	Bullet() = default;
	//Bullet(const Transform& transform) : // something wrong with this call.
	//	Actor{ transform }
	//{
	//}

	void Update(float dt) override;
	void Read(const json::value_t& value) override;

private:

	// Inherited via Actor
	void onCollision(parabellum::Actor* other);
};
}