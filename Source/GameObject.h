#pragma once

#include "Game.h"
#include "TextManager.h"

class GameObject
{
public:
	GameObject(const char* filename, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xpos, ypos;

	SDL_Texture* texture;
	SDL_Rect srcRect, dectRect;
};