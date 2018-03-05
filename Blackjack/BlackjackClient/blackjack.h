#pragma once

#include <SDL.h>

#include "card.h"
#include "drawable.h"

class Blackjack
{
public:
	Blackjack();
	~Blackjack();

	bool init();
	void execute();
	void input();
	void update();
	void draw();
private:
	static const int WINDOW_HEIGHT;
	static const int WINDOW_WIDTH;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Drawable background;

	Card my_card;

	bool running;
};