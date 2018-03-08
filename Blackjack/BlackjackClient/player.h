#pragma once

#include "card.h"
#include "drawable_batch.h"
#include "utilities.h"

class Player
{
public:
	Player();
	~Player();

	void add_to_hand(Card* card);
	void update_hand();
	void draw_hand(SDL_Renderer* renderer);

	void set_hand_origin_x(int x);
	void set_hand_origin_y(int y);
	void set_score(int new_score);
	void set_spawn_x(int new_x);
	void set_spawn_y(int new_y);
private:
	static const int CARD_GAP;

	DrawableBatch card_batch;

	std::vector<Card*> hand;
	
	int hand_origin_x;
	int hand_origin_y;
	int score;
	int spawn_x;
	int spawn_y;
};