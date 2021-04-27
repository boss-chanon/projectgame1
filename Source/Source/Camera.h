#pragma once

#include "Game.h"
#include "Player.h"
#include <iostream>

class Camera
{
public:
	static SDL_Point center();
	static int xmove();
	static int ymove();
private:
	static int xpos, ypos;
	static SDL_Point cen;
};