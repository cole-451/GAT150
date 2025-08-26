#pragma once
#include "RendererComponent.h"

namespace parabellum {
	class SpriteRenderer : public RendererComponent {
	public:
		
		CLASS_PROTOTYPE(SpriteRenderer)

			void Start() override;
	


		// Inherited via RendererComponent
		void Update(float dt) override;

		void draw(Renderer& renderer) override;

	public:
		std::string textureName;
		res_t<Texture> texture;

		// Inherited via Serializable
		void Read(const json::value_t& value) override;
	};
}