#pragma once
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
	
	class Actor {
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

		Transform m_transform;
		float getRadius();
		//std::shared_ptr<Model> m_model;
		Scene* m_scene{ nullptr };
		res_t<Texture> m_texture;
	protected:

	};
}