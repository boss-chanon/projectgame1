#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Camera.h"
#include "Player.h"

class GameObject
{
public:
	GameObject(const char* filename, int width, int height, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xpos, ypos;
	int width, height;
	bool renderState;
	
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};