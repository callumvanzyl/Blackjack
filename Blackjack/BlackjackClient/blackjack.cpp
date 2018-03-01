#include "blackjack.h"
#include "card.h"
#include "utilities.h"

const int Blackjack::WINDOW_HEIGHT = 512;
const int Blackjack::WINDOW_WIDTH = 512;

Blackjack::Blackjack()
{
}


Blackjack::~Blackjack()
{
}

bool Blackjack::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		utilities::print_error("Could not initiate SDL");
		return false;
	}
	utilities::print_success("Successfully initiated SDL");

	window = SDL_CreateWindow(
		"Blackjack",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL
	);

	if (window == NULL)
	{
		utilities::print_error("Could not create window");
		return false;
	}
	utilities::print_success("Successfully created window");

	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC
	);

	if (renderer == NULL)
	{
		utilities::print_error("Could not create rendering context for window");
		return false;
	}
	utilities::print_success("Successfully created rendering context for window");

	running = true;
	
	background.set_texture(renderer, "background.png");

	return true;
}

void Blackjack::execute()
{
	while (running)
	{
		update();
		draw();
	}
}

void Blackjack::update()
{
}

void Blackjack::draw()
{
	SDL_RenderClear(renderer);
	background.draw(renderer);
	card_batch.draw_batch(renderer);
	SDL_RenderPresent(renderer);
}