#pragma once
#include "SDL.h"

class Collision
{
public:
	static bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
};