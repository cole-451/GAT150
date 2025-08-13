#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

namespace parabellum {
	class Renderer
	{
	public:


		Renderer() = default;

		bool initialize();

		bool createWindow(const std::string& name, int width, int height, bool fullscreen = false);

		void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8  a = 185);

		void setColor(float r, float g, float b, float  a = 1.0f);

		void clear();

		void present();

		void GTFO();

		void drawline(float x1, float y1, float x2, float y2);

		void drawdot(float x, float y);

		int getWidth() const { return w_width; }

		int getHeight() const { return w_height; }

		friend class Texture;
		void DrawTexture(Texture& texture, float x, float y);
		void DrawTexture(Texture& texture, float x, float y, float angle, float scale = 1);



	private:
		friend class Text;

		SDL_Window* current_window = nullptr;
		SDL_Renderer* renderer = 0;

		int w_width{ 0 };
		int w_height{ 0 };
	};
}


