#pragma once

#include "Game.h"
#include "Attack.h"
#include "Camera.h"
#include "GameObject.h"
#include <iostream>

class Player
{
public:
	Player(const char* filename);
	~Player();

	void move(int speed);
	void render();
	void walk();

	static int speed;
	static SDL_Point position;
	static SDL_Rect srcRect, destRect;

private:
	int aniPos, aniWalk, walkCount = 0;
	std::string direction;
	
	Attack* attack;
	
	SDL_Point area;
	SDL_Texture* texture;
	SDL_Point radius;
	SDL_Point center;
};