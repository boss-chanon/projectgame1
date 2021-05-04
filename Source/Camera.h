#pragma once

#include "Game.h"
#include "Player.h"
#include <iostream>

class Camera
{
public:
	static void move(SDL_Point position, int speed);
	static SDL_Point center();

	static int xmove;
	static int ymove;
};