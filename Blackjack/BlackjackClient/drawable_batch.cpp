#include "drawable_batch.h"

DrawableBatch::DrawableBatch()
{
}

DrawableBatch::~DrawableBatch()
{
}

void DrawableBatch::add_to_batch(Drawable* object) // push drawable pointer to front of stack
{
	batch.push_back(object);
}

void DrawableBatch::update_batch() // update a collection of drawable objects, all at once
{
	for (Drawable* v : batch)
	{
		v->update();
	}
}

void DrawableBatch::draw_batch(SDL_Renderer* renderer) // draw a collection of drawable objects, all at once
{
	for (Drawable* v : batch)
	{
		v->draw(renderer);
	}
}