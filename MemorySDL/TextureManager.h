#pragma once
#include "Game.h"
#include <string>

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName);
	static void render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
	static SDL_Texture* loadFromRenderedText(std::string textureText, SDL_Color textColor);
};