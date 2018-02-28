#pragma once

#include "drawable.h"

const enum SUITS { CLUBS, DIAMONDS, HEARTS, SPADES };

class Card : public Drawable
{
public:
	Card();
	~Card();
private:
	SUITS suit;
	int value;
};