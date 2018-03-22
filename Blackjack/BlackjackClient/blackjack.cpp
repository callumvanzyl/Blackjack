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
	if (SDL_Init(SDL_INIT_VIDEO) == -1) // Attempt to initiate SDL video
	{
		print_error("Could not initiate SDL");
		return false; // Quit if unsuccessful
	}
	print_success("Successfully initiated SDL");

	window = SDL_CreateWindow( // Create a window
		"Blackjack",
		SDL_WINDOWPOS_CENTERED, // Centered on screen
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL // No flags
	);

	if (window == NULL) // Make sure the window was created
	{
		print_error("Could not create window");
		return false;
	}
	print_success("Successfully created window");

	renderer = SDL_CreateRenderer( // Attach rendering context to window
		window,
		-1,
		SDL_RENDERER_ACCELERATED | // Flags to enable accelerated 2D rendering and VSync
		SDL_RENDERER_PRESENTVSYNC
	);

	if (renderer == NULL)
	{
		print_error("Could not create rendering context for window");
		return false;
	}
	print_success("Successfully created rendering context for window");

	deck.populate(renderer); // Add cards to deck object
	
	background.set_texture(renderer, "background.png");

	deck_image.set_texture(renderer, "deck.png"); // Image of the deck, no functional value
	deck_image.set_x_pos(15);
	deck_image.set_y_pos(199);

	shadow.set_texture(renderer, "shadow.png"); // Overlay

	won_splash.set_texture(renderer, "won.png"); // Endgame splash screens
	lost_splash.set_texture(renderer, "lost.png");

	player_one.set_hand_origin_x(20); // Set origin position of player hand (where cards originate)
	player_one.set_hand_origin_y(368);

	player_one.set_spawn_x(20); // Set initial position of all cards added to hand
	player_one.set_spawn_y(194);

	player_two.set_hand_origin_x(20);
	player_two.set_hand_origin_y(20);

	player_two.set_spawn_x(20);
	player_two.set_spawn_y(194);

	hit_button.set_texture(renderer, "hit_buttons.png");
	hit_button.set_x_pos(175);
	hit_button.set_y_pos(229);

	hold_button.set_texture(renderer, "hold_buttons.png");
	hold_button.set_x_pos(345);
	hold_button.set_y_pos(229);

	state = TAKING_TURNS; // Game state, when this is TAKING_TURNS, procedure in 'thread' will run.

	thread = new std::thread(&Blackjack::take_turn_thread, this); // Process players turns in a seperate thread

	running = true;

	return true;
}

void Blackjack::execute() // Start game loop
{
	while (running)
	{
		input();
		update();
		draw();
	}
}

void Blackjack::input() // Process players input events (not buttons presses)
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

void Blackjack::update() // Logical updates to data structures
{
	player_one.update();
	player_two.update();
	hit_button.update();
	hold_button.update();
}

void Blackjack::draw() // Draw objects on the screen
{
	SDL_RenderClear(renderer);
	background.draw(renderer);
	if (!player_one.holding && awaiting)
	{
		hit_button.draw(renderer);
		hold_button.draw(renderer);
	}
	deck_image.draw(renderer);
	player_one.draw(renderer);
	player_two.draw(renderer);
	shadow.draw(renderer);

	if (state == WON) // The player has won
	{
		won_splash.draw(renderer);
	}

	if (state == LOST)
	{
		lost_splash.draw(renderer);
	}

	SDL_RenderPresent(renderer); // Copy current frame to screen
}

void Blackjack::take_turn_thread()
{
	for (int i = 0; i < 10; i++)
	{
		if (player_one.get_score() > player_two.get_score() && player_two.holding)
		{
			player_one.holding = true;
			state = WON;
		}

		if (!player_one.holding)
		{
			awaiting = true; // Is false when the player has pressed a button
			while (true)
			{
				SDL_Delay(20); // Prevents massive CPU usage
				if (hit_button.is_pressed()) // If hit button was pressed...
				{
					SDL_Delay(100);
					awaiting = false;
					break;
				}
				else if (hold_button.is_pressed())
				{
					SDL_Delay(100);
					awaiting = false;
					player_one.holding = true;
					break;
				}
			}
		}

		if (!player_one.holding)
		{
			Card* new_card1 = deck.draw_random_card();
			SDL_Delay(10);
			player_one.add_to_hand(new_card1);
			SDL_Delay(10);

			std::string text1 = ("Player score set to " + std::to_string(player_one.get_score()));
			print_warning(text1);

			SDL_Delay(500);
		}

		if (player_one.get_score() == 21)
		{
			state = WON;
		}
		if (player_one.get_score() > 21)
		{
			state = LOST;
		}

		if (state != TAKING_TURNS)
		{
			SDL_Delay(5000);
			running = false;
		}

		SDL_Delay(500);

		if (player_two.get_score() >= 17)
		{
			player_two.holding = true;
		}

		if (player_two.get_score() > player_one.get_score() && player_one.holding)
		{
			player_two.holding = true;
			state = LOST;
		}

		if (!player_two.holding)
		{
			Card* new_card2 = deck.draw_random_card();
			SDL_Delay(10);
			player_two.add_to_hand(new_card2);
			SDL_Delay(10);

			std::string text2 = ("Computer score set to " + std::to_string(player_two.get_score()));
			print_warning(text2);

			SDL_Delay(500);
		}

		if (player_two.get_score() == 21)
		{
			state = LOST;
		}
		if (player_two.get_score() > 21)
		{
			state = WON;
		}

		if (player_two.holding && player_one.holding && player_one.get_score() == player_two.get_score())
		{
			state = WON;
		}

		if (state != TAKING_TURNS)
		{
			SDL_Delay(5000);
			running = false;
		}
	}
}