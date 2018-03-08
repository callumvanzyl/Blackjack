#pragma once

#include <thread>

#include <SDL.h>

#include "deck.h"
#include "drawable.h"
#include "player.h"

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

	void take_turn_thread();
private:
	static const int WINDOW_HEIGHT;
	static const int WINDOW_WIDTH;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Deck deck;

	Drawable background;
	Drawable deck_image;
	Drawable shadow;

	Player player_one;
	Player player_two;

	std::thread* thread;

	bool running;
};