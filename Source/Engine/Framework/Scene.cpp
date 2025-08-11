#include "Scene.h"
#include "Actor.h"
#include "../Renderer/Renderer.h"
#include <memory>
#include <vector>
#include "../Core/StringHelper.h"


namespace parabellum {
	void Scene::Update(float dt) {
		for (auto& actor : actors) {
			actor->Update(dt);
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

		for (auto& actorA : actors) {
			for (auto& actorB : actors) {
				if (actorA == actorB || (!actorA->stillAlive || !actorB->stillAlive)) continue;
				//if one is destroyed, dont do anything

				float distance = vec2{ actorA->m_transform.position - actorB->m_transform.position}.length();
				std::cout << actorA->getRadius() << " " << actorB->getRadius() << std::endl;

				// if your distance is less than or equal to the SUM of both of the actor's radius
					if (distance <= actorA->getRadius() + actorB->getRadius()){
					actorA->onCollision(actorB.get());
					actorB->onCollision(actorA.get());
				}
			}
		}
	}

	void Scene::Draw(class Renderer& renderer) {
		for (auto& actor : actors) {
			actor->Draw(renderer);
		}
	}
	void Scene::AddActor(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this; // check on this later. im not sure if this is correct.
		actors.push_back(std::move(actor));

	}


	
	


	// check for collisions
	
	}
