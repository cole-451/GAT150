#pragma once
#include "Framework/Component.h"
#include "Physics/PhysicsBody.h"

namespace parabellum {
	class RigidBody : public Component {
	public:

		PhysicsBody::PhysicsBodyDef bodydef;

		vec2 size{ 0,0 };
		vec2 velocity{ 0,0 };

		// Inherited via Component
		void Update(float dt) override;

	public:
		RigidBody() = default;
		RigidBody(const RigidBody& other);
		CLASS_PROTOTYPE(RigidBody)

		void Start() override;
		void Read(const json::value_t& value) override;

		void ApplyForce(const vec2 force);
		void ApplyTorque(float radians);

	private:
		std::unique_ptr<PhysicsBody> m_physbod;

	};
}