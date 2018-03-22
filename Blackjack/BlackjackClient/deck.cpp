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
	srand(time(NULL));  // get a random card  from the deck
	int i = rand() % cards.size();
	Card* card = cards[i];
	cards.erase(cards.begin() + i); // remove card from deck so we dont draw it again
	return card;
}

void Deck::populate(SDL_Renderer* renderer)
{
	for (int i = 0; i <= 39; i++) // add a ton of cards to the deck, simplified via use of id to card function
	{
		Card* c = id_to_card(renderer, i);
		cards.push_back(c);
	}
}