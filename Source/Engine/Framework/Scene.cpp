#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "Components/ColliderComponent.h"
#include "Core/StringHelper.h"


namespace parabellum {
	void Scene::Update(float dt) {
		for (auto& actor : actors) {
			if (actor->active) {

				actor->Update(dt);
			}
		}

		//remove destroyed actors
		for (auto iter = actors.begin(); iter != actors.end();) {
			if (!(*iter)->stillAlive) {
				iter = actors.erase(iter);
			}
			else {
				iter++;
			}
		}
		//collision
		for (auto& actorA : actors) {
			for (auto& actorB : actors) {
				if (actorA == actorB || (!actorA->stillAlive || !actorB->stillAlive)) continue;
				//if one is destroyed, dont do anything
				auto colliderA = actorA->getComponent<ColliderComponent>();
				auto colliderB = actorB->getComponent<ColliderComponent>();

				// make sure both actors have colliders
				if (!colliderA || !colliderB) continue;

				if (colliderA->checkCollision(*colliderB)) {
					actorA->onCollision(actorB.get());
					actorB->onCollision(actorA.get());

				}
			}
		}
	}

	void Scene::Draw(class Renderer& renderer) {
		for (auto& actor : actors) {
			if (actor->active) {

				actor->Draw(renderer);
			}
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this; // check on this later. im not sure if this is correct.
		actors.push_back(std::move(actor));

	}

	void Scene::Read(const json::value_t& value)
	{
		//read actor
		if (JSON_HAS(value, prototypes)) {
			//read prototypes
			for (auto& actorValue : JSON_GET(value, prototypes).GetArray()) {
				auto actor = Factory::Instance().Create<Actor>("Actor");
				actor->Read(actorValue);

				std::string name = actor->name;
				Factory::Instance().RegisterPrototype<Actor>(name, std::move(actor));
			}
		}

		//read actual actors
		if (JSON_HAS(value, actors)) {

			for (auto& actorValue : JSON_GET(value, actors).GetArray()) {
				auto actor = Factory::Instance().Create<Actor>("Actor");
				actor->Read(actorValue);

				AddActor(std::move(actor));
			}
		}
	}

	void Scene::RemoveAllActors(bool force)
	{
		for (auto iter = actors.begin(); iter != actors.end();) {
			if (!(*iter)->persistent || force) {
				iter = actors.erase(iter);
			}
			else {
				iter++;
			}
		}






		// check for collisions

	}
}
