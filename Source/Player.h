#pragma once

#include "Game.h"

class Player
{
public:
	void init(const char* filename, int x, int y);
	void move();
	void render();
	void walk();
private:
	int xpos, ypos;
	int speed = 3;
	int positionX, positionY;
	int aniPos, aniWalk = 0;
	int walkCount = 0;

	SDL_Texture* texture;
	SDL_Rect srcRect, dectRect;
};