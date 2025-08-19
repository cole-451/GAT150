#pragma once
#include "RendererComponent.h"

namespace parabellum {
	class SpriteRenderer : public RendererComponent {
	public:
		

		// Inherited via RendererComponent
		void Update(float dt) override;

		void draw(Renderer& renderer) override;

	public:
		std::string textureName;

		// Inherited via Serializable
		void Read(const json::value_t& value) override;
	};
}