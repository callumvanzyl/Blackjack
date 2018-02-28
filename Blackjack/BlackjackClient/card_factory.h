#pragma once

#include "card.h"

class CardFactory
{
public:
	CardFactory();
	~CardFactory();

	Card create_card();
};