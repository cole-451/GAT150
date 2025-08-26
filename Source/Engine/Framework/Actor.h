#pragma once
#include "Component.h"
#include "../Math/Transform.h"
#include "../Renderer/Mesh.h"
#include <string>
#include <memory>
#include "EnginePCH.h"
#include "../Core/StringHelper.h"
//#include "Scene.h"
#include "../Framework/Scene.h"
#include "../Framework/Game.h"
#include "Renderer/Texture.h"
#include "Physics/Collidable.h"

namespace parabellum {

	

	class Scene;

	class Actor : public Object, public ICollidable {
	public:

		std::string tag;



		bool stillAlive = true;

		float lifespan = 0;

		Actor() = default;
		Actor(const Transform& transform) : //todo: replace the texture in your params with a component calling said texture.
			m_transform{ transform }
			//m_scene{scene}
		{
		}

		Actor(const Actor& other);
		//virtual std::unique_ptr<Object> Clone() { return std::make_unique<Actor>(*this); } already being cloned below.

		CLASS_PROTOTYPE(Actor)

		virtual void Update(float dt);

		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return m_transform; }

		virtual void OnCollision(Actor* other) override;

		void addComponent(std::unique_ptr<Component> component);

		template <typename T>
		T* getComponent();


		template <typename T>
		std::vector<T*> getComponents();


		Transform m_transform;
		bool persistent = false;

		//std::shared_ptr<Model> m_model;
		Scene* m_scene{ nullptr };

		std::vector<std::unique_ptr<Component>> m_components;
		// Inherited via Serializable
		void Read(const json::value_t& value) override;

		virtual void Start();

		virtual void Destroyed();
	protected:



	};

	template<typename T>
	inline T* Actor::getComponent()
	{
		for (auto& component : m_components) {
			auto result = dynamic_cast<T*>(component.get());
			if (result) {
				return result;
			}
		}
		return nullptr;
	}

	template<typename T>
	inline std::vector<T*> Actor::getComponents()
	{
		std::vector<T*> results;
		for (auto& component : m_components) {
			auto result = dynamic_cast<T*>(component.get());
			if (result) {
				results.push_back(result);
			}

		}
			return results; // does this go here or back in the for loop?
	}
}