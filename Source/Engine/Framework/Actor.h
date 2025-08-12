#pragma once
#include "Component.h"
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <string>
#include <memory>
#include "EnginePCH.h"
#include "../Core/StringHelper.h"
//#include "Scene.h"
#include "../Framework/Scene.h"
#include "../Framework/Game.h"
#include "Renderer/Texture.h"

namespace parabellum {

	class Scene;

	class Actor : public Object {
	public:

		std::string tag;



		bool stillAlive = true;

		float lifespan = 0;

		Actor() = default;
		Actor(const Transform& transform, res_t<Texture> texture) : //todo: replace the texture in your params with a component calling said texture.
			m_transform{ transform },
			m_texture{ texture }
			//m_scene{scene}
		{
		}

		virtual void Update(float dt);

		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return m_transform; }

		virtual void onCollision(Actor* other) = 0;

		void addComponent(std::unique_ptr<Component> component);

		template <typename T>
		T* getComponent();


		template <typename T>
		std::vector<T*> getComponents();


		Transform m_transform;
		float getRadius();
		//std::shared_ptr<Model> m_model;
		Scene* m_scene{ nullptr };

		res_t<Texture> m_texture;
		std::vector<std::unique_ptr<Component>> m_components;
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

			return std::vector<T*>(); // fix this up! ask for the video early.
		}
	}
}