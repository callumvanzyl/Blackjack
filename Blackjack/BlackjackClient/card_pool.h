#pragma once

#include <stack>

#include "card.h"

class CardPool
{
public:
	static const int POOL_SIZE;

	std::stack<Card> pool;

	CardPool();
	~CardPool();

	Card acquire_card();
	void release_card();
};