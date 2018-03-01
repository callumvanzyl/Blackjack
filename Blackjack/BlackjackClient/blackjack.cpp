#include "blackjack.h"
#include "utilities.h"

const int Blackjack::WINDOW_HEIGHT = 512;
const int Blackjack::WINDOW_WIDTH = 512;

double a = 0; // For testing

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
	
	background.set_texture(renderer, "background.png");
	
	card1.set_texture(renderer, "card.png");
	card1.set_x_pos(100);
	card1.set_y_pos(100);

	card2.set_texture(renderer, "card.png");
	card2.set_width(50);
	card2.set_height(75);
	card2.set_x_pos(400);
	card2.set_y_pos(400);

	card_batch.add_to_batch(&card1);
	card_batch.add_to_batch(&card2);

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
	a += 0.1;
	int x = cos(a) * 50;
	int y = sin(a) * 50;
	card1.set_x_pos(x);
	card1.set_y_pos(y);
}

void Blackjack::draw()
{
	SDL_RenderClear(renderer);
	background.draw(renderer);
	card_batch.draw_batch(renderer);
	SDL_RenderPresent(renderer);
}