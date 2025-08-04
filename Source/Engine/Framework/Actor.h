#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"
#include <string>
#include <memory>
#include "../Core/StringHelper.h"
//#include "Scene.h"
#include "../Framework/Scene.h"
#include "../Framework/Game.h"


namespace parabellum {

	class Scene; // this fixes the 6 errors i get but fucks something else up
	
	class Actor {
	public:

		std::string name;
		std::string tag;

		vec2 velocity{ 0,0 };

		float damping{ 0.0f };


		bool stillAlive = true;

		float lifespan = 0;

		Actor() = default;
		Actor(const Transform& transform, class std::shared_ptr<Model> model) :
			m_transform{ transform },
			m_model{ model }
			//m_scene{scene}
		{
		}

		virtual void Update(float dt);

		virtual void Draw(class Renderer& renderer);

		Transform& GetTransform() { return m_transform; }

		virtual void onCollision(Actor* other) = 0;

		Transform m_transform;
		float getRadius();
		std::shared_ptr<Model> m_model;
		Scene* m_scene;

	protected:

	};
}