#include "card_factory.h"

int card_to_id(Card card)
{
	return 0;
}

Card* create_card(SDL_Renderer* renderer, SUITS suit, int value)
{
	Card* new_card = new Card(renderer, suit, value);
	return new_card;
}

Card* id_to_card(SDL_Renderer* renderer, int id)
{
	SUITS suit;
	switch (id / 10) // value truncates, get first digit in number, matches to corresponding suit
	{
	case(0):
		suit = CLUBS;
		break;
	case(1):
		suit = DIAMONDS;
		break;
	case(2):
		suit = HEARTS;
		break;
	case(3):
		suit = SPADES;
		break;
	}

	int value = id % 10 + 1; // id mod 10+1 is card value, eg if id is 23 the suit is 2 (hearts) and value is 3+1

	Card* new_card = new Card(renderer, suit, value);
	return new_card;
}