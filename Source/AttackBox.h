#pragma once

#include "Game.h"

struct AttackBox
{
	SDL_Rect hitRect, destRect, checkRect;
	SDL_Point center, goal;
	double angle;
	int move, xpos ,ypos, xmove, ymove;
};