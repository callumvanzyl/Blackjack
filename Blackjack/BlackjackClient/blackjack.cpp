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
	
	Card* test_card = new Card(SPADES, 10);
	test_card->set_texture(renderer, "card.png");

	Card* test_card2 = new Card(SPADES, 10);
	test_card2->set_texture(renderer, "card.png");

	player_one.set_hand_origin_x(20);
	player_one.set_hand_origin_y(20);
	player_one.set_spawn_height(-200);

	player_one.add_to_hand(test_card);
	player_one.add_to_hand(test_card2);

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
	player_one.update_hand();
	player_two.update_hand();
}

void Blackjack::draw()
{
	SDL_RenderClear(renderer);
	background.draw(renderer);
	player_one.draw_hand(renderer);
	player_two.draw_hand(renderer);
	SDL_RenderPresent(renderer);
}