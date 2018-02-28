#pragma once

#include <stack>

#include "card.h"

class CardPool
{
public:
	CardPool();
	~CardPool();

	Card acquire_card();
	void release_card();
private:
	static const int POOL_SIZE;

	std::stack<Card> pool;
};