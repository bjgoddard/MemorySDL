#include "BWindow.h"

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
	return false;
}

SDL_Renderer* BWindow::createRenderer()
{
	return nullptr;
}

void BWindow::handleEvent(SDL_Event& e)
{
}

void BWindow::free()
{
}

int BWindow::getWidth()
{
	return 0;
}

int BWindow::getHeight()
{
	return 0;
}

bool BWindow::hasMouseFocus()
{
	return false;
}

bool BWindow::hasKeyboardFocus()
{
	return false;
}

bool BWindow::isMinimized()
{
	return false;
}
