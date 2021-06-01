#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Camera.h"
#include "GameSetting.h"

class Map
{
public:
	Map(const char* filename);

	void updateMap();
	void drawMap();

	int width, height;
private:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};