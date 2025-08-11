#pragma once
#include "Framework/Component.h"

namespace parabellum {
	class RendererComponent : public Component {
	public:
		virtual void draw(class Renderer& renderer) = 0;
	};
}