#pragma once

#include "JsonManager.h"
#include "Game.h"

class GameSetting
{
public:
	static void load(const char* filename);
	static void setSize(int width, int height);
	static SDL_Point charactorSize();

	static string equipment, inventory, item, map, stat, playerData;
	static int width, height, widthSTD, heightSTD, CharactorStdWidth, CharactorStdHeight;
	static double scaleX, scaleY;
};