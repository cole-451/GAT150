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
		ProcessCollisionEvents();
	}

	void Physics::ProcessCollisionEvents()
	{
		b2ContactEvents contactEvents = b2World_GetContactEvents(m_worldID);

		//begin contact
		for (int i = 0; i < contactEvents.beginCount; i++) {
			b2ContactBeginTouchEvent* contactevent = contactEvents.beginEvents + i;

			if (!b2Shape_IsValid(contactevent->shapeIdA) || !b2Shape_IsValid(contactevent->shapeIdB)) continue;

			b2BodyId bodyA = b2Shape_GetBody(contactevent->shapeIdA);
			b2BodyId bodyB = b2Shape_GetBody(contactevent->shapeIdB);

			Actor* actorA = (Actor*)b2Body_GetUserData(bodyA);
			if (!actorA || !actorA->stillAlive || !actorA->active) continue;
			Actor* actorB = (Actor*)b2Body_GetUserData(bodyB);
			if (!actorB || !actorB->stillAlive || !actorB->active) continue;

			actorA->OnCollision(actorB);
			actorB->OnCollision(actorA);

		}
		//end contact
		for (int i = 0; i < contactEvents.endCount; i++) {
			b2ContactEndTouchEvent* contactevent = contactEvents.endEvents + i;

			if (!b2Shape_IsValid(contactevent->shapeIdA) || !b2Shape_IsValid(contactevent->shapeIdB)) continue;

			b2BodyId bodyA = b2Shape_GetBody(contactevent->shapeIdA);
			b2BodyId bodyB = b2Shape_GetBody(contactevent->shapeIdB);

			Actor* actorA = (Actor*)b2Body_GetUserData(bodyA);
			if (!actorA || !actorA->stillAlive || !actorA->active) continue;
			Actor* actorB = (Actor*)b2Body_GetUserData(bodyB);
			if (!actorB || !actorB->stillAlive || !actorB->active) continue;

			actorA->OnCollision(actorB);
			actorB->OnCollision(actorA);

		}
		//register contact with sensors
		b2SensorEvents sensorevents = b2World_GetSensorEvents(m_worldID);


		for (int i = 0; i < sensorevents.beginCount; i++) {
			b2SensorBeginTouchEvent* sensorevent = sensorevents.beginEvents + i;
		if (!b2Shape_IsValid(sensorevent->sensorShapeId) || !b2Shape_IsValid(sensorevent->visitorShapeId)) continue;

			b2BodyId bodyA = b2Shape_GetBody(sensorevent->sensorShapeId);
			b2BodyId bodyB = b2Shape_GetBody(sensorevent->visitorShapeId);

			Actor* actorA = (Actor*)b2Body_GetUserData(bodyA);
			if (!actorA || !actorA->stillAlive || !actorA->active) continue;
			Actor* actorB = (Actor*)b2Body_GetUserData(bodyB);
			if (!actorB || !actorB->stillAlive || !actorB->active) continue;

			actorA->OnCollision(actorB);
			actorB->OnCollision(actorA);

		}
	}


}