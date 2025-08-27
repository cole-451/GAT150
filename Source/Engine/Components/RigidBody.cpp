#include "EnginePCH.h"
#include "RigidBody.h"
#include "Core/json.h"
#include "Components/SpriteRenderer.h"
#include "Engine.h"

namespace parabellum {
	FACTORY_REGISTER(RigidBody)

	void RigidBody::Update(float dt) {
		//owner->m_transform.position += velocity * dt;
		owner->m_transform.position = m_physbod->getPosition();
		owner->m_transform.rotation = math::radius_to_degrees(m_physbod->getAngle());
}

	RigidBody::RigidBody(const RigidBody& other)
	{
		bodydef = other.bodydef;
		size = other.size;

		if (other.m_physbod) {
			m_physbod = std::make_unique<PhysicsBody>(*other.m_physbod);
		}
	}

	void RigidBody::Start()
	{
		bodydef.actor = owner;
		if (size.x == 0 && size.y == 0) {
			auto spriterenderer = owner->getComponent<SpriteRenderer>();
			if (spriterenderer) {
				size = spriterenderer->texture->GetSize();
			}

		}

		m_physbod = std::make_unique<PhysicsBody>(owner->m_transform, size, bodydef, getEngine().GetPhysics());
	}

	void RigidBody::Read(const json::value_t& value)
	{
		//JSON_READ(value, velocity); //check and see if you need to do the special vec2 version
		JSON_READ(value, size);
		//JSON_READ(value, scale);


		JSON_READ_NAME(value, "gravityScale", bodydef.gravityScale);
		JSON_READ_NAME(value, "linearDamping", bodydef.linearDamping);
		JSON_READ_NAME(value, "angularDamping", bodydef.angularDamping);
		JSON_READ_NAME(value, "constrainAngle", bodydef.constrainAngle);
		JSON_READ_NAME(value, "isDynamic", bodydef.isDynamic);
		JSON_READ_NAME(value, "friction", bodydef.friction);
		JSON_READ_NAME(value, "restitution", bodydef.restitution);
		JSON_READ_NAME(value, "density", bodydef.density);
		JSON_READ_NAME(value, "isSensor", bodydef.isSensor);

		std::string shapeName;
		JSON_READ_NAME(value, "shape", shapeName);

		if (!shapeName.empty()) {
			if (equalsIgnoreCase(shapeName, "box")) bodydef.shape = PhysicsBody::Shape::Box;
			else if (equalsIgnoreCase(shapeName, "capsule")) bodydef.shape = PhysicsBody::Shape::Capsule;
			else if (equalsIgnoreCase(shapeName, "circle")) bodydef.shape = PhysicsBody::Shape::Circle;
		}
	}

	void RigidBody::ApplyForce(const vec2 force) {
		m_physbod->ApplyForce(force);
	}

	void RigidBody::ApplyTorque(float radians) {
		m_physbod->ApplyTorque(radians);
	}
}



