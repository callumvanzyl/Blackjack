#include "card.h"

const int Card::CARD_WIDTH = 91;
const int Card::CARD_HEIGHT = 124;

Card::Card(SDL_Renderer* renderer, SUITS new_suit, int new_value)
{
	suit = new_suit;
	value = new_value;

	this->set_texture(renderer, "cards.png"); // TODO: dont load duplicate spritesheet into memory every time a card is instantised

	int suit_value;

	switch (suit) // For fetching image on sprite sheet
	{
	case(CLUBS):
		suit_value = 0;
		break;
	case(DIAMONDS):
		suit_value = 1;
		break;
	case(HEARTS):
		suit_value = 2;
		break;
	case(SPADES):
		suit_value = 3;
		break;
	}

	set_src_w(CARD_WIDTH);
	set_src_h(CARD_HEIGHT);

	set_src_x(CARD_WIDTH*(value - 1)); // Get image on sprite sheet
	set_src_y(CARD_HEIGHT*suit_value); 
}

Card::~Card()
{
}

int Card::get_value()
{
	return value;
}