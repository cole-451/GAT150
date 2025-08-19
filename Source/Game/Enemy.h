#pragma once
#include "Framework/Actor.h"
#include "Renderer/Texture.h"
#include "Framework/Component.h"
#include "Core/Factory.h"


namespace parabellum{
class Enemy : public Component {
public:

	float speed = 200;
	Enemy() = default;

	void Update(float dt) override;
private:




	// Inherited via Actor
	void onCollision(class parabellum::Actor* other) ;

};
}