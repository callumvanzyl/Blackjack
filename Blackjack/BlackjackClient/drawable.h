#pragma once

#include <string>

#include <SDL.h>

#include "instance.h"

class Drawable : public Instance
{
public:
	Drawable();
	~Drawable();

	void draw();
	void set_sprite(std::string path);
	void set_x(int x);
	void set_y(int y);
private:
	SDL_Texture* texture;

	bool active;
};