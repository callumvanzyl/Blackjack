#pragma once

#include <vector>

#include "card_factory.h"
#include "drawable.h"

class Deck : public Drawable
{
public:
	Deck();
	~Deck();

	Card* draw_random_card();
	void populate(SDL_Renderer* renderer);
private:
	std::vector<Card*> cards;
};