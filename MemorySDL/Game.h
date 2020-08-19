#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>



class Game
{
public:
	Game() {}
	~Game() {}

	void Init();
	void Input();
	void Update();
	void Render();
	void Clean();
	bool isRunning() { return running; }
	static SDL_Renderer* renderer;
	static TTF_Font* myFont;
	int getScreenWidth() { return SCREEN_WIDTH;  }
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 640;
	

private:

	SDL_Event event;
	SDL_Window* window = NULL;
	bool running = true;


	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

	
};