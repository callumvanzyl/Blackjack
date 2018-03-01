#pragma once

#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "instance.h"

class Drawable : public Instance
{
public:
	Drawable();
	~Drawable();

	void draw(SDL_Renderer* renderer);
	void set_texture(SDL_Renderer* renderer, std::string path);
	void set_x(int x);
	void set_y(int y);
private:
	SDL_Texture* texture;

	bool active;
};