#include "EnginePCH.h"
#include "RigidBody.h"

namespace parabellum {
	FACTORY_REGISTER(RigidBody)
	void RigidBody::Update(float dt) {
		owner->m_transform.position += velocity * dt;
}

}



