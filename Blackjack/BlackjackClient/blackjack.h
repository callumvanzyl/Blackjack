#pragma once

#include <SDL.h>

#include "card.h"
#include "drawable.h"
#include "drawable_batch.h"

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

	Card card1; // For testing
	Card card2; // For testing

	SDL_Window* window;
	SDL_Renderer* renderer;

	Drawable background;
	DrawableBatch card_batch;

	bool running;
};