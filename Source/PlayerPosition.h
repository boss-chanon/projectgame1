#pragma once

#include "Camera.h"

class PlayerPosition
{
public:
	static void sizeSet(int width, int height);
	static void move(SDL_Point position, int speed);
	static SDL_Rect getPosition();
	static void setPosition(int x, int y);

	static int width, height, xpos, ypos;
};