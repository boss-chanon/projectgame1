#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Camera.h"

class Map
{
public:
	Map(const char* filename);

	void loadMap();
	void drawMap();

private:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};