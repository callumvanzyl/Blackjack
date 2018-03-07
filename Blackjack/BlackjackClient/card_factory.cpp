#include "card_factory.h"

Card* create_card(SDL_Renderer* renderer, SUITS suit, int value)
{
	Card* new_card = new Card(renderer, suit, value);
	return new_card;
}