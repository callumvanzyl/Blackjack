#include "drawable_batch.h"

DrawableBatch::DrawableBatch()
{
}

DrawableBatch::~DrawableBatch()
{
}

void DrawableBatch::add_to_batch(Drawable* object)
{
	batch.push_back(object);
}

void DrawableBatch::update_batch()
{
	for (Drawable* v : batch)
	{
		v->update();
	}
}

void DrawableBatch::draw_batch(SDL_Renderer* renderer)
{
	for (Drawable* v : batch)
	{
		v->draw(renderer);
	}
}