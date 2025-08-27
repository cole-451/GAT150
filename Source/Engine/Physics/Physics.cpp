#include "Physics.h"

namespace parabellum {
	float Physics::ms_PixelsPerUnit = 48.0f;

	bool Physics::Initialize() {
		b2WorldDef worldDef = b2DefaultWorldDef();
		worldDef.gravity = b2Vec2{ 0.0f, 10.0f };
		m_worldID = b2CreateWorld(&worldDef);

		return true;
	}

	void Physics::Shutdown() {
		b2DestroyWorld(m_worldID);
	}

	void Physics::Update(float dt) {
		b2World_Step(m_worldID, 1.0f / 60.0f, 4); //physics frame-rate (60fps)
	}


}