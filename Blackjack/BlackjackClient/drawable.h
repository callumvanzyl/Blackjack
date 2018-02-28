#pragma once

#include "instance.h"

class Drawable : public Instance
{
public:
	Drawable();
	~Drawable();

	bool active = true;

	void set_x(int &x);
	void set_y(int &y);
};