#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Collision.h"
#include "Stat.h"
#include <iostream>
#include <math.h>

#ifndef PI
#define PI 3.14159265
#endif // PI

class Attack
{
public:
	Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad);
	~Attack();

	void setStat(Stat stat);

	void slash(std::string direction, int xpos, int ypos, SDL_Point cen);
	void pierce(std::string direction, int xpos, int ypos, SDL_Point cen);
	void blunt(std::string direction, int xpos, int ypos, SDL_Point cen);
	void shoot(std::string direction, int xpos, int ypos, SDL_Point cen);

	bool hit(SDL_Rect rect);
	int damage();
	void attackDirection(std::string direction);
	void render();
private:
	int speed, aniX, aniY, x, y, move, xpos, ypos;
	double angle, xmove, ymove;
	bool ATKstage = false;

	Stat stat;

	SDL_Rect srcRect, destRect, objRect, hitRect;
	SDL_Point area, center, radius;
	SDL_Texture* texture;
};