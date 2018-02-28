#include "drawable.h"
#include "utilities.h"

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::draw()
{

}

void Drawable::set_sprite(std::string path)
{
	if (utilities::is_valid_path(path) == 1)
	{
		return;
	}
}

void Drawable::set_x(int x)
{

}

void Drawable::set_y(int y)
{

}