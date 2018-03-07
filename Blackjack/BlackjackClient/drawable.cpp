#include "drawable.h"
#include "utilities.h"

#define PI 3.14159265

const int Drawable::TWEENING_SPEED = 10;

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::update()
{
	int x_dist = x_target - x_pos;
	int y_dist = y_target - y_pos;

	double angle = SDL_fmod(atan2(-y_dist, x_dist), PI * 2);

	if (x_target != x_pos)
	{
		int new_x = x_pos + (int)(cos(angle) * TWEENING_SPEED);
		if (x_target > x_pos)
		{
			new_x = new_x > x_target ? x_target : new_x;
		}
		else
		{
			new_x = new_x < x_target ? x_target : new_x;
		}
		set_x_pos(new_x);
	}

	if (y_target != y_pos)
	{
		int new_y = y_pos - (int)(sin(angle) * TWEENING_SPEED);
		if (y_target > y_pos)
		{
			new_y = new_y > y_target ? y_target : new_y;
		}
		else
		{
			new_y = new_y < y_target ? y_target : new_y;
		}
		set_y_pos(new_y);
	}
}

void Drawable::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, &src_rect, &dst_rect);
}

void Drawable::set_texture(SDL_Renderer* renderer, std::string path)
{
	if (!is_valid_path(path))
	{
		std::string text = "Could not load texture '" + path + "'";
		print_error(text);
		return;
	}

	SDL_Surface* surface = IMG_Load(path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	width = w;
	height = h;

	src_rect.w = w;
	src_rect.h = h;

	dst_rect.w = w;
	dst_rect.h = h;

	src_rect.x = 0;
	src_rect.y = 0;

	dst_rect.x = 0;
	dst_rect.y = 0;
}

int Drawable::get_width()
{
	return width;
}

void Drawable::set_width(int w)
{
	dst_rect.w = w;
	width = w;
}

int Drawable::get_height()
{
	return height;
}

void Drawable::set_height(int h)
{
	dst_rect.h = h;
	height = h;
}

int Drawable::get_x_pos()
{
	return x_pos;
}

void Drawable::set_x_pos(int x)
{
	dst_rect.x = x;
	x_pos = x;
}

int Drawable::get_y_pos()
{
	return y_pos;
}

void Drawable::set_y_pos(int y)
{
	dst_rect.y = y;
	y_pos = y;
}

void Drawable::set_x_target(int x)
{
	x_target = x;
}

void Drawable::set_y_target(int y)
{
	y_target = y;
}