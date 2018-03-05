#include "drawable.h"
#include "utilities.h"

const int Drawable::TWEENING_SPEED = 5;

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::update()
{
	int current_x = get_x_pos();
	int current_y = get_y_pos();

	if (current_x != x_target)
	{
		float x_dir = normalise(x_target - current_x, 0, 512, -1, 1)*TWEENING_SPEED;
		set_x_pos(current_x - (int)x_dir);
	}

	if (current_y != y_target)
	{
		float y_dir = normalise(y_target - current_y, 0, 512, -1, 1)*TWEENING_SPEED;
		set_y_pos(current_y - (int)y_dir);
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