#pragma once

#include "drawable.h"

const enum SUITS { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card : public Drawable
{
public:
	Card(SUITS suit, int value);
	~Card();
private:
	SUITS suit;

	int value;
};