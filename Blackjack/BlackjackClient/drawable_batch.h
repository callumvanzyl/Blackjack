#pragma once

#include <vector>

#include "drawable.h"

class DrawableBatch
{
public:
	DrawableBatch();
	~DrawableBatch();

	void add_to_batch(Drawable* object);
	void draw_batch(SDL_Renderer* renderer);
private:
	std::vector<Drawable*> batch;
};