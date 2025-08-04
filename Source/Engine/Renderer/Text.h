#pragma once
#include "Font.h"
#include "../Math/Vector3.h"
#include "Renderer.h"


struct SDL_Texture;

namespace parabellum {
	class Text {
	public:
		Text() = default;
		Text(std::shared_ptr<Font> font) : m_font{ font } {} 
		~Text();

		bool Create(Renderer& renderer, const std::string& text, const vec3& color);
		void Draw(Renderer& renderer, float x, float y);

	private:
		friend class Renderer;
		std::shared_ptr<Font> m_font{ nullptr };
		SDL_Texture* m_texture{ nullptr };
	};
}