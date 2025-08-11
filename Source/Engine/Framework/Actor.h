#pragma once
#include "Component.h"
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <string>
#include <memory>
#include "../Core/StringHelper.h"
//#include "Scene.h"
#include "../Framework/Scene.h"
#include "../Framework/Game.h"
#include "Renderer/Texture.h"

namespace parabellum {

	class Scene; 
	
	class Actor : public Component {
	public:

		std::string name;
		std::string tag;

		vec2 velocity{ 0,0 };

		float damping{ 0.0f };


		bool stillAlive = true;

		float lifespan = 0;

		Actor() = default;
		Actor(const Transform& transform, res_t<Texture> texture) : //todo: replace the model system with a sprite system
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

		Transform m_transform;
		float getRadius();
		//std::shared_ptr<Model> m_model;
		Scene* m_scene{ nullptr };
		res_t<Texture> m_texture;
		std::vector<std::unique_ptr<Component>> m_components;
	protected:

	};
}