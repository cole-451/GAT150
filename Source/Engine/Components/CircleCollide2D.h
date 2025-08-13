#pragma once
#include "ColliderComponent.h"
namespace parabellum {
	class CircleCollide2D : public ColliderComponent {
	public:
		float radius{ 0 };

		// Inherited via ColliderComponent
		void Update(float dt) override;

		bool checkCollision(ColliderComponent& other) override;

	};
}