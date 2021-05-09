#pragma once

#include "Game.h"
#include "Attack.h"
#include "Camera.h"
#include "GameObject.h"
#include "Stat.h"
#include "Inventory.h"
#include "PlayerPosition.h"
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

	SDL_Rect srcRect, destRect;

private:
	int aniPos, aniWalk, walkCount = 0;
	int speed, fileWidth, fileHeight;
	std::string direction;
	
	Stat stat;
	Attack* attack;
	Inventory* inventory;

	SDL_Texture* texture;
	SDL_Point radius, center, area, position;
};