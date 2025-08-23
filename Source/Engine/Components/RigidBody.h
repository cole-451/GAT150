#pragma once
#include "Framework/Component.h"

namespace parabellum {
	class RigidBody : public Component {
	public:
		CLASS_PROTOTYPE(RigidBody)

		vec2 velocity{ 0,0 };

		// Inherited via Component
		void Update(float dt) override;

	public:
		void Read(const json::value_t& value) override;

	};
}