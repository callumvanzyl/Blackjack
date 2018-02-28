#pragma once

#include "drawable.h"

const enum SUITS { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card : public Drawable
{
public:
	SUITS suit;
	int value;

	Card();
	~Card();
};