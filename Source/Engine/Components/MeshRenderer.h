#pragma once
#include "RendererComponent.h"

namespace parabellum {
	class MeshRenderer : public RendererComponent {
	public:


		// Inherited via RendererComponent
		void Update(float dt) override;

		void draw(Renderer& renderer) override;

		CLASS_PROTOTYPE(MeshRenderer)

	public:
		std::string meshName;
		void Read(const json::value_t& value) override;

	};
}