#include "EnginePCH.h"
#include "RigidBody.h"

namespace parabellum {
	void RigidBody::Update(float dt) {
		owner->m_transform.position += velocity * dt;
}

}



