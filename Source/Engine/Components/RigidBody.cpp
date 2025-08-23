#include "EnginePCH.h"
#include "RigidBody.h"
#include "Core/json.h"

namespace parabellum {
	FACTORY_REGISTER(RigidBody)
	void RigidBody::Update(float dt) {
		owner->m_transform.position += velocity * dt;
}

	void RigidBody::Read(const json::value_t& value)
	{
		JSON_READ(value, velocity); //check and see if you need to do the special vec2 version
	}

}



