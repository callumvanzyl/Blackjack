#include "blackjack.h"
#include "utilities.h"

int main(int argc, char *argv[])
{
	Blackjack blackjack;

	if (blackjack.init())
	{
		blackjack.execute();
		return 0;
	}
	else
	{
		return 1;
	}
}