#pragma once
#include "RendererComponent.h"

namespace parabellum {
	class MeshRenderer : public RendererComponent {
	public:


		// Inherited via RendererComponent
		void Update(float dt) override;

		void draw(Renderer& renderer) override;

	public:
		std::string meshName;
	};
}