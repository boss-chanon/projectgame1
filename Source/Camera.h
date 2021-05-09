#pragma once

#include "Game.h"
#include "PlayerPosition.h"
#include <iostream>

class Camera
{
public:
	static SDL_Point center();
	static void set(int x, int y);

	static int xcam;
	static int ycam;
};