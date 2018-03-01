#include "blackjack.h"
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
	
	my_card.set_texture(renderer, "card.png");
	my_card.set_x_pos(50);
	my_card.set_y_pos(50);

	card_batch.add_to_batch(my_card);

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

		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				my_card.set_y_pos(my_card.get_y_pos() + 5);
				break;
			case SDLK_DOWN:
				my_card.set_y_pos(my_card.get_y_pos() - 5);
				break;
			case SDLK_LEFT:
				my_card.set_x_pos(my_card.get_x_pos() - 5);
				break;
			case SDLK_RIGHT:
				my_card.set_x_pos(my_card.get_x_pos() + 5);
				break;
			case SDLK_ESCAPE:
				running = false;
				break;
			}
		}
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