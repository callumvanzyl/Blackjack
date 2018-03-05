#include "player.h"

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
}

void Player::draw_hand(SDL_Renderer* renderer)
{
	card_batch.draw_batch(renderer);
}