#pragma once

#include "Game.h"
#include "TextManager.h"
#include <iostream>

class Attack
{
public:
	Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad);
	~Attack();

	void attack(std::string direction, int xpos, int ypos, SDL_Point cen);
	void attackDirection(std::string direction);
	void render();

	bool ATKstage = false;

private:
	int speed;
	int aniX = 0;
	int	aniY;															
	double angle;

	SDL_Point area;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Point center;
	SDL_Point radius;
};