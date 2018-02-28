#include "drawable_batch.h"

DrawableBatch::DrawableBatch()
{
}

DrawableBatch::~DrawableBatch()
{
}

void DrawableBatch::add_to_batch(Drawable object)
{
	batch.push_back(object);
}

void DrawableBatch::draw_batch()
{
	for (std::vector<Drawable>::iterator it = batch.begin(); it != batch.end(); it++)
	{
		it->draw();
	}
}