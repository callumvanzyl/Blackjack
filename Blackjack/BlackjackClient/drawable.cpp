#include <math.h>

#include "drawable.h"
#include "utilities.h"

#define PI 3.14159265

const int Drawable::TWEENING_SPEED = 5;

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::update()
{
	int x_current = get_x_pos();
	int y_current = get_y_pos();

	int x_dist = x_target - x_current;
	int y_dist = y_target - y_current;

	double angle = fmod(atan2(-y_dist, x_dist), PI * 2);

	if (x_current != x_target)
	{
		set_x_pos(x_current + (cos(angle) * TWEENING_SPEED));
	}

	if (y_current != y_target)
	{
		set_y_pos(y_current - (sin(angle) * TWEENING_SPEED));
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