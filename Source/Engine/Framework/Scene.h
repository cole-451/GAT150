#pragma once
#include <vector>
#include <memory> 
#include "Actor.h"
#include "../Core/StringHelper.h"
#include <list>
#include "Core/Serializable.h"

namespace parabellum {
	class Scene : public Serializable {
	public:
		Scene(class Game* game) :
			m_game{game}{ }


		void Update(float dt);

		void Draw(class Renderer& renderer);

		void AddActor(std::unique_ptr<class Actor> actor);

		template <typename T>

		std::vector<T> getActorsByTag(const std::string& tag);

		template<typename T = Actor>
		T* GetActorByName(const std::string& name);

		class Game* getGame() { return m_game; }

		// Inherited via Serializable
		void Read(const json::value_t& value) override;
		void RemoveAllActors(bool force = false);


	private:
		
		class Game* m_game{ nullptr };

		
		std::list<std::unique_ptr<Actor>> actors; //list is having a lot of trouble.



	};
	template <typename T>
	inline std::vector<T> Scene::getActorsByTag(const std::string& tag) {
		std::vector<T> results;
		for (auto& actor : actors) {
			if (toLower(actor->tag) == toLower(tag)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					results.push_back(object);
				}
			}
		}
		return results;
	}
	template<typename T>
	T* Scene::GetActorByName(const std::string& name)
	{

		for (auto& actor : actors) {
			if (toLower(actor->name) == toLower(name)) {
				T* object = dynamic_cast<T*>(actor.get());
				if (object) {
					return object;
				}
			}
		}
		return nullptr;// maybe causing errors?
	}
}
