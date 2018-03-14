#include "button.h"

const int Button::BUTTON_WIDTH = 152;
const int Button::BUTTON_HEIGHT = 57;

Button::Button()
{
	set_src_w(BUTTON_WIDTH);
	set_src_h(BUTTON_HEIGHT);
}


Button::~Button()
{
}

bool Button::is_pressed()
{
	return (is_intersecting_cursor() && SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1));
}

bool Button::is_intersecting_cursor()
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	return (
		x > get_x_pos() && x < get_x_pos() + BUTTON_WIDTH &&
		y > get_y_pos() && y < get_y_pos() + BUTTON_HEIGHT
		);
}

void Button::update()
{
	if (is_pressed())
	{
		set_src_y(114);
	}
	else if (is_intersecting_cursor())
	{
		set_src_y(57);
	}
	else
	{
		set_src_y(0);
	}
}