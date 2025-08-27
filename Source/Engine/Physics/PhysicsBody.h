#pragma once
#include <box2d/box2d.h>

namespace parabellum {
	class PhysicsBody {
	public:
		enum class Shape {
			Box,
			Circle,
			Capsule
		};

		struct PhysicsBodyDef {
			// body
			float gravityScale = 1; // overall scale of how much gravity we want on something
			float linearDamping = 0.2f; //how much do we slow
			float angularDamping = 0.2f; // how much do we slow down, with torque
			bool  constrainAngle = false; //constrain and make sure that an actor doesnt break its perspective
			bool  isDynamic = true; // are you affected by physics or not?

			// material
			float friction = 0.3f; //how much do I slide or stick
			float restitution = 0.5f; // how much bounce do I have?
			float density = 1.0f; //how heavy am I?

			// shape
			Shape shape = Shape::Box;
			bool isSensor = false; //is this thing a trigger state?

			class Actor* actor{ nullptr };
		};

	public:
		PhysicsBody(const Transform& transform, const vec2 size, const PhysicsBodyDef& def, const class Physics& physics);
		~PhysicsBody();

		vec2 getPosition();
		float getAngle();

		void ApplyForce(const vec2 force);
		void ApplyTorque(float radians);

		void setVelocity(const vec2& velocity);

	private:
		b2BodyId m_bodyID{ b2_nullBodyId };
	};
}