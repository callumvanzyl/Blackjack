#include "drawable.h"
#include "utilities.h"

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void Drawable::set_texture(SDL_Renderer* renderer, std::string path)
{
	if (!utilities::is_valid_path(path))
	{
		std::string text = "Could not load texture '" + path + "'";
		utilities::print_error(text);
		return;
	}

	SDL_Surface* surface = IMG_Load(path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Drawable::set_x(int x)
{

}

void Drawable::set_y(int y)
{

}