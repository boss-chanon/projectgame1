#pragma once

#include "Game.h"
#include "Attack.h"
#include "Camera.h"
#include "GameObject.h"
#include "Stat.h"
#include <iostream>

class Player
{
public:
	Player(const char* filename);
	~Player();

	void update();
	void move();
	void render();
	void walk();

private:
	int aniPos, aniWalk, walkCount = 0;
	int speed;
	std::string direction;
	
	Stat stat;
	Attack* attack;

	SDL_Texture* texture;
	SDL_Point radius, center, area, position;
	SDL_Rect srcRect, destRect;
};