#pragma once
#include "Framework/Component.h"

namespace parabellum {
	class RigidBody : public Component {
	public:
		vec2 velocity{ 0,0 };

		// Inherited via Component
		void Update(float dt) override;

	public:

	};
}