#include "Game.h"

Game* game = nullptr;

//const int FPS = 60;
//const int frameDelay = 1000 / FPS;
//Uint32 frameStart;
//int frameTime;



int main(int argc, char* args[])
{
	game = new Game();

	game->Init();

	while (game->isRunning())
	{
		/*frameStart = SDL_GetTicks();*/



		game->Input();
		game->Update();
		game->Render();

		/*frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}*/
	}
	game->Clean();

	return 0;
}