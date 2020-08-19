#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"
#include "BTimer.h"
#include <sstream>
#include "Dot.h"


GameObject* player;

SDL_Renderer* Game::renderer = nullptr;

TTF_Font* Game::myFont = nullptr;

SDL_Texture* fontTexture;

BTimer fpsTimer;
std::stringstream timeText;
SDL_Color textColor;
int countedFrames = 0;

SDL_Texture* dotTexture;
Dot* dot;


//Set the wall
SDL_Rect wall;






void Game::Init()
{
	
	//SDL Init
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL Init failed " << SDL_GetError() << std::endl;
		running = false;
	}
	else
	//IF SDL INIT SUCCESS
	{
		window = SDL_CreateWindow("MemorySDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "SDL Window creation error:" << SDL_GetError() << std::endl;
			running = false;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
	}

	//Image INIT
	int imageFlags = IMG_INIT_PNG;
	if (!IMG_Init(imageFlags) & imageFlags)
	{
		std::cout << "SDL_Image init failed" << IMG_GetError() << std::endl;
		running = false;
	}
	else
	{
		/*SDL_Surface* screenSurface = SDL_GetWindowSurface(window);*/
		/*playerTex = TextureManager::LoadTexture("assets/foo.png", renderer);*/
		player = new GameObject("assets/foo.png", 0, 0);
		/*dotTexture = TextureManager::LoadTexture("assets/dot.bmp");*/
		dot = new Dot();

	}

	//TTF Init
	if (TTF_Init() == -1)
	{
		std::cout << "TTF failed to initialize" << TTF_GetError() << std::endl;
		running = false;
	}
	else
	{
		myFont = TTF_OpenFont("assets/arial.ttf", 28);
		if (myFont == NULL)
		{
			std::cout << "Failed to load arial font" << TTF_GetError() << std::endl;
			running = false;
		}
		else
		{
			/*SDL_Color textColor = { 255,255,0 };
			fontTexture = TextureManager::loadFromRenderedText("Howdy", textColor);*/
		}
	}
	fpsTimer.start();
	running = true;


	wall.x = 300;
	wall.y = 40;
	wall.w = 40;
	wall.h = 400;

	
}

void Game::Input()
{
	

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				running = false;
				break;
			}
			
		default:
			break;
		}
		dot->handleEvent(event);
	}

	dot->move(wall);

}

void Game::Update()
{
	player->Update();
	dot->update();
	
	float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}
	timeText.str("");
	timeText << "Average FPS" << avgFPS;
	
	fontTexture = TextureManager::loadFromRenderedText(timeText.str().c_str(), textColor);

	SDL_SetWindowTitle(window, timeText.str().c_str());
}

void Game::Render()
{
	SDL_RenderClear(renderer);
	//ADD STUFF TO RENDER
	player->Render();
	/*SDL_RenderCopy(renderer, fontTexture, NULL, NULL);*/
	/*SDL_RenderCopy(renderer, dotTexture, NULL, NULL);*/

	//render wall
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(renderer, &wall);
	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
	dot->render();
	SDL_RenderPresent(renderer);
	++countedFrames;
}

void Game::Clean()
{


	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
