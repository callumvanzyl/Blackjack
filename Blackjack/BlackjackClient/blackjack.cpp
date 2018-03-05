#include "blackjack.h"
#include "player.h"
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
		print_error("Could not initiate SDL");
		return false;
	}
	print_success("Successfully initiated SDL");

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
		print_error("Could not create window");
		return false;
	}
	print_success("Successfully created window");

	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC
	);

	if (renderer == NULL)
	{
		print_error("Could not create rendering context for window");
		return false;
	}
	print_success("Successfully created rendering context for window");
	
	background.set_texture(renderer, "background.png");

	my_card.set_texture(renderer, "card.png");

	my_card.set_x_target(0);
	my_card.set_y_target(300);

	running = true;

	return true;
}

void Blackjack::execute()
{
	while (running)
	{
		input();
		update();
		draw();
	}
}

void Blackjack::input()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			running = false;
		}
	}
}

void Blackjack::update()
{
	my_card.update();
}

void Blackjack::draw()
{
	SDL_RenderClear(renderer);
	background.draw(renderer);
	my_card.draw(renderer);
	SDL_RenderPresent(renderer);
}