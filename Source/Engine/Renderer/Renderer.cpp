#include "Renderer.h"
#include "Core/Logger.h"
#include "Texture.h"
#include <SDL3/SDL.h>
#include <iostream>
#include <string>
#include "../Math/Vector2.h"

namespace parabellum {

    bool Renderer::initialize()
    {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            std::cout << SDL_GetError() << std::endl;
            return false;
        }

        if (!TTF_Init()) {
            Logger::Error("TTF init error");
            return false;
        }

        else {
            return true;
        }
    }

    bool Renderer::createWindow(const std::string& name, int width, int height)
    {
        current_window = SDL_CreateWindow(name.c_str(), 1280, 1024, 0);
        if (current_window == nullptr) {
            Logger::Error("SDL initwindow error!");       
            SDL_Quit();
            return false;
        }

        renderer = SDL_CreateRenderer(current_window, NULL);
        if (renderer == nullptr) {
            Logger::Error("TTF createRenderer error!");
            SDL_DestroyWindow(current_window);
            SDL_Quit();
            return false;
        }

        return true;
    }

    void Renderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8  a)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }

    void Renderer::setColor(float r, float g, float b, float  a) {

        SDL_SetRenderDrawColorFloat(renderer, r, g, b, a);
    }


    void Renderer::clear()
    {
        SDL_RenderClear(renderer);
    }

    void Renderer::present()
    {
        SDL_RenderPresent(renderer);
    }

    void Renderer::GTFO()
    {
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(current_window);
        SDL_Quit();
    }



    void Renderer::drawline(float x1, float y1, float x2, float y2)
    {
        SDL_RenderLine(renderer, x1, y1, x2, y2);
    }

    void Renderer::drawdot(float x, float y)
    {
        SDL_RenderPoint(renderer, x, y);
    }

    void Renderer::DrawTexture(Texture* texture, float x, float y)
    {
        vec2 size = texture->GetSize();

        SDL_FRect destRect;
        destRect.x = x;
        destRect.y = y; //* scale?
        destRect.w = size.x;
        destRect.h = size.y;

        // https://wiki.libsdl.org/SDL3/SDL_RenderTexture
        SDL_RenderTexture(renderer, texture->m_texture, NULL, &destRect);
    }
    void Renderer::DrawTexture(Texture* texture, float x, float y, float angle, float scale)
    {
        vec2 size = texture->GetSize();

        SDL_FRect destRect;
        destRect.w = size.x * scale;
        destRect.h = size.y * scale;
        destRect.x = x - (destRect.w * 0.5f);
        destRect.y = y - (destRect.h * 0.5f);

        // https://wiki.libsdl.org/SDL3/SDL_RenderTexture
        SDL_RenderTextureRotated(renderer, texture->m_texture, NULL, &destRect, NULL, NULL, SDL_FLIP_NONE);
    }
}