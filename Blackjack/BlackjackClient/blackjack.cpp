#include "blackjack.h"
#include "utilities.h"

const int Blackjack::WINDOW_HEIGHT = 512;
const int Blackjack::WINDOW_WIDTH = 512;

Blackjack::Blackjack()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		print_error("Could not initiate SDL");
		return;
	}
	print_success("Successfully initiated SDL");

	window_ = SDL_CreateWindow(
		"Blackjack",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL
	);

	renderer_ = SDL_CreateRenderer(
		window_,
		-1,
		SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC
	);

	SDL_Quit();
}


Blackjack::~Blackjack()
{
}