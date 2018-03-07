#include "card.h"

Card::Card(SDL_Renderer* renderer, SUITS suit, int value)
{
	this->set_texture(renderer, "card.png");
}

Card::~Card()
{
}