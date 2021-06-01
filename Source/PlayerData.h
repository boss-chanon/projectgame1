#pragma once

#include "JsonManager.h"
#include "GameSetting.h"
#include "Game.h"
#include "PlayerPosition.h"
#include "MapManager.h"

class PlayerData
{
public:
	static bool login(string ID, string password);
	static void load();
	static void save();

	static string ID, password, image, map;
	static SDL_Point position;
public:
	static json data;
};