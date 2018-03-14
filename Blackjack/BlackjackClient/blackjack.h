#pragma once

#include <thread>

#include <SDL.h>
#include <SDL_ttf.h>

#include "button.h"
#include "deck.h"
#include "drawable.h"
#include "player.h"

const enum GAME_STATE { LOST, TAKING_TURNS, WON };

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

	Drawable won_splash;
	Drawable lost_splash;

	Player player_one;
	Player player_two;

	Button hit_button;
	Button hold_button;

	std::thread* thread;

	GAME_STATE state;

	bool running;
	bool awaiting;
};