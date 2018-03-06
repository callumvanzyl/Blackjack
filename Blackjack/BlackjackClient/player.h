#pragma once

#include "card.h"
#include "drawable_batch.h"

class Player
{
public:
	Player();
	~Player();

	void add_to_hand(Card card);
	void draw_hand(SDL_Renderer* renderer);
private:
	DrawableBatch card_batch;

	std::vector<Card> hand;
	
	int score;
};