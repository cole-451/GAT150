#pragma once
#include "ColliderComponent.h"
namespace parabellum {
	class CircleCollide2D : public ColliderComponent {
	public:
		float radius{ 0 };

		// Inherited via ColliderComponent
		void Update(float dt) override;

		CLASS_PROTOTYPE(CircleCollide2D)


		bool checkCollision(ColliderComponent& other) override;

		void Read(const json::value_t& value) override;

	};
}