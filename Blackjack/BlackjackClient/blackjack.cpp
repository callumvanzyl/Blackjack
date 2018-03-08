#include "blackjack.h"
#include "card_factory.h"
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

	deck.populate(renderer);
	
	background.set_texture(renderer, "background.png");

	deck_image.set_texture(renderer, "deck.png");
	deck_image.set_x_pos(15);
	deck_image.set_y_pos(199);

	shadow.set_texture(renderer, "shadow.png");

	player_one.set_hand_origin_x(20);
	player_one.set_hand_origin_y(20);

	player_one.set_spawn_x(20);
	player_one.set_spawn_y(194);

	player_two.set_hand_origin_x(20);
	player_two.set_hand_origin_y(368);

	player_two.set_spawn_x(20);
	player_two.set_spawn_y(194);

	thread = new std::thread(&Blackjack::take_turn_thread, this);

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
	deck_image.draw(renderer);
	player_one.draw_hand(renderer);
	player_two.draw_hand(renderer);
	shadow.draw(renderer);
	SDL_RenderPresent(renderer);
}

void Blackjack::take_turn_thread()
{
	for (int i = 0; i < 10; i++)
	{
		Card* new_card = deck.draw_random_card();
		player_one.add_to_hand(new_card);
		SDL_Delay(1000);
		Card* new_card2 = deck.draw_random_card();
		player_two.add_to_hand(new_card2);
		SDL_Delay(1000);
	}
}