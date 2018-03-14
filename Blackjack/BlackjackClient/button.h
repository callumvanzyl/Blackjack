#pragma once

#include "drawable.h"

const enum TYPE { HIT, HOLD };

class Button : public Drawable
{
public:
	Button();
	~Button();

	bool is_pressed();
	bool is_intersecting_cursor();

	void update();
private:
	static const int BUTTON_WIDTH;
	static const int BUTTON_HEIGHT;
};