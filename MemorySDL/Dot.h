#pragma once
#include "SDL.h"

class Dot
{
public:
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	static const int DOT_VEL = 10;

	Dot();

	void handleEvent(SDL_Event& e);

	void move(SDL_Rect &wall);
	
	void update();

	void render();

private:
	int mPosX, mPosY;

	int mVelX, mVelY;

	SDL_Texture* dotTexture;

	SDL_Rect srcRect, destRect;

	SDL_Rect mCollider;
	
};