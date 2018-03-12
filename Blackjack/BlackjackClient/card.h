#pragma once

#include "drawable.h"

const enum SUITS { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card : public Drawable
{
public:
	Card(SDL_Renderer* renderer, SUITS new_suit, int new_value);
	~Card();

	int get_value();
private:
	static const int CARD_WIDTH;
	static const int CARD_HEIGHT;

	SUITS suit;

	int value;
};