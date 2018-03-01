#pragma once

#include <SDL.h>

#include "drawable.h"
#include "drawable_batch.h"

class Blackjack
{
public:
	Blackjack();
	~Blackjack();

	bool init();
	void execute();
	void update();
	void draw();
private:
	static const int WINDOW_HEIGHT;
	static const int WINDOW_WIDTH;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Drawable background;
	DrawableBatch card_batch;

	bool running;
};