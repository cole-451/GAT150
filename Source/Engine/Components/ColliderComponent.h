#pragma once
#include "Framework/Component.h"

namespace parabellum {
	class ColliderComponent : public Component {
	public:
		virtual bool checkCollision(ColliderComponent& other) = 0;
		
	};
}