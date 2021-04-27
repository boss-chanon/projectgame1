#pragma once

#include "Game.h"
#include "TextManager.h"
#include <iostream>
#include <math.h>

#ifndef PI
#define PI 3.14159265
#endif // !PI


class Attack
{
public:
	Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad);
	~Attack();

	void slash(std::string direction, int xpos, int ypos, SDL_Point cen);
	void pierce(std::string direction, int xpos, int ypos, SDL_Point cen);
	void blunt(std::string direction, int xpos, int ypos, SDL_Point cen);
	void shoot(std::string direction, int xpos, int ypos, SDL_Point cen);

	void attackDirection(std::string direction);
	void render();

private:
	int speed, aniX, aniY, x, y, move;															
	double angle;
	bool ATKstage = false;

	SDL_Point area;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Point center;
	SDL_Point radius;
};