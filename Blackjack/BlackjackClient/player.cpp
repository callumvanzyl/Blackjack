#include "player.h"

const int Player::CARD_GAP = 120;

Player::Player()
{
}

Player::~Player()
{
}

void Player::add_to_hand(Card* card)
{
	card_batch.add_to_batch(card);
	hand.push_back(card);

	int x_pos = hand_origin_x + ((hand.size()-1) * CARD_GAP);

	card->set_x_pos(spawn_x);
	card->set_y_pos(spawn_y);

	card->set_x_target(x_pos);
	card->set_y_target(hand_origin_y);
}

void Player::update_hand()
{
	card_batch.update_batch();
}

void Player::draw_hand(SDL_Renderer* renderer)
{
	card_batch.draw_batch(renderer);
}

void Player::set_hand_origin_x(int new_x)
{
	hand_origin_x = new_x;
}

void Player::set_hand_origin_y(int new_y)
{
	hand_origin_y = new_y;
}


void Player::set_score(int new_score)
{
	score = new_score;
}

void Player::set_spawn_x(int new_x)
{
	spawn_x = new_x;
}

void Player::set_spawn_y(int new_y)
{
	spawn_y = new_y;
}