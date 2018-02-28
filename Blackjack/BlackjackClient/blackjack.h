#pragma once

#include <SDL.h>

class Blackjack
{
public:
	static const int WINDOW_HEIGHT;
	static const int WINDOW_WIDTH;

	Blackjack();
	~Blackjack();

private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;
};