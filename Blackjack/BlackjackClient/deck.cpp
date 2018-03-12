#include <time.h>

#include "deck.h"

Deck::Deck()
{
}

Deck::~Deck()
{
}

Card* Deck::draw_random_card()
{
	srand(time(NULL));
	int i = rand() % cards.size();
	Card* card = cards[i];
	cards.erase(cards.begin() + i);
	return card;
}

void Deck::populate(SDL_Renderer* renderer)
{
	for (int i = 0; i <= 39; i++)
	{
		Card* c = id_to_card(renderer, i);
		cards.push_back(c);
	}
}