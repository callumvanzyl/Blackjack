#pragma once

#include "card.h"

int card_to_id(Card card);
Card* create_card(SDL_Renderer* renderer, SUITS suit, int value);
Card* id_to_card(SDL_Renderer* renderer, int id);