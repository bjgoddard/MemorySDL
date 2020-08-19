#include "TextureManager.h"
#include <iostream>

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* tempSurf = IMG_Load(fileName);
    SDL_SetColorKey(tempSurf, SDL_TRUE, SDL_MapRGB(tempSurf->format, 0, 0xFF, 0xFF));
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurf);
    SDL_FreeSurface(tempSurf);
    return tex;
}

void TextureManager::render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dest, NULL, NULL, flip);
}

SDL_Texture* TextureManager::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(Game::myFont, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        std::cout << "Unable to render text surface" << std::endl;
        return NULL;
    } 
    else
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
        SDL_FreeSurface(textSurface);
        return tex;
    }
    
}
