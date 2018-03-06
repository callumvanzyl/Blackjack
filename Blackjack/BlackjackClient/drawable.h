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

	void update();
	void draw(SDL_Renderer* renderer);

	void set_texture(SDL_Renderer* renderer, std::string path);

	int get_width();
	void set_width(int w);

	int get_height();
	void set_height(int h);

	int get_x_pos();
	void set_x_pos(int x);

	int get_y_pos();
	void set_y_pos(int y);

	void set_x_target(int x);
	void set_y_target(int y);
private:
	static const int TWEENING_SPEED;

	SDL_Texture* texture;

	SDL_Rect src_rect;
	SDL_Rect dst_rect;

	int width, height;
	int x_pos, y_pos;
	int y_target, x_target;

	bool active;
};