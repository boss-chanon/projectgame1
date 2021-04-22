#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Camera.h"

class Map
{
public:
	Map(const char* filename, int width, int heigth);
	~Map();

	void loadMap();
	void drawMap();

private:
	int width, height;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};