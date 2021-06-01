#pragma once

#include "Game.h"
#include "Attack.h"
#include "Camera.h"
#include "GameObject.h"
#include "Stat.h"
#include "StatManager.h"
#include "Inventory.h"
#include "PlayerPosition.h"
#include "Equipment.h"
#include "GameSetting.h"
#include <iostream>

class Player
{
public:
	Player(string filename, string ID);
	~Player();

	void update();
	void move();
	void render();
	void walk();

	SDL_Rect srcRect, destRect;

private:
	int aniPos, aniWalk, walkCount = 0;
	int speed, fileWidth, fileHeight;
	string direction, name;
	
	Stat stat;
	Inventory* inventory;
	Equipment* equipment;

	SDL_Texture* texture;
	SDL_Point center, position;
};