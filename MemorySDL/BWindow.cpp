#include "BWindow.h"

SDL_Renderer* renderer;

BWindow::BWindow()
{
	window = NULL;
	mouseFocus = false;
	keyboardFocus = false;
	fullScreen = false;
	minimized = false;
	width = 0;
	height = 0;
}

bool BWindow::init()
{
	window = SDL_CreateWindow("MemorySDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window != NULL)
	{
		mouseFocus = true;
		keyboardFocus = true;
		width = 800;
		height = 640;
	}
	return window != NULL;
}

SDL_Renderer* BWindow::createRenderer()
{
	return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void BWindow::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_WINDOWEVENT)
	{
		switch (e.window.event)
		{
			//Get new dimensions and repaint on window size change
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			width = e.window.data1;
			height = e.window.data2;
			SDL_RenderPresent(renderer);
			break;

			//Repaint on exposure
		case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(renderer);
			break;

			//Mouse entered window
		case SDL_WINDOWEVENT_ENTER:
			mouseFocus = true;
			
			break;

			//Mouse left window
		case SDL_WINDOWEVENT_LEAVE:
			mouseFocus = false;
			break;

			//Window has keyboard focus
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			keyboardFocus = true;
			break;

			//Window lost keyboard focus
		case SDL_WINDOWEVENT_FOCUS_LOST:
			keyboardFocus = false;
			break;

			//Window minimized
		case SDL_WINDOWEVENT_MINIMIZED:
			minimized = true;
			break;

			//Window maxized
		case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
			break;

			//Window restored
		case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
			break;
		}
	}
	else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN)
	{
		if (fullScreen)
		{
			SDL_SetWindowFullscreen(window, SDL_FALSE);
			fullScreen = false;
		}
		else
		{
			SDL_SetWindowFullscreen(window, SDL_TRUE);
			fullScreen = true;
			minimized = false;
		}
	}
}

void BWindow::free()
{
	if (window != NULL)
	{
		SDL_DestroyWindow(window);
	}
	mouseFocus = false;
	keyboardFocus = false;
	width = 0;
	height = 0;
}

int BWindow::getWidth()
{
	return width;
}

int BWindow::getHeight()
{
	return height;
}

bool BWindow::hasMouseFocus()
{
	return mouseFocus;
}

bool BWindow::hasKeyboardFocus()
{
	return keyboardFocus;
}

bool BWindow::isMinimized()
{
	return minimized;
}
