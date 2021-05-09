#pragma once

#include "Map.h"
#include "JsonManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"
#include "SpawnArea.h"
#include "PlayerPosition.h"
#include <stdlib.h>

class MapManager
{
public:
	static void loadData(string filename, string name);
	static void spawnObject(const int spawnTime);
	static bool spawnOverlab(SDL_Rect rec);
	//static void changeMap(SDL_Rect rec);
	static void saveData();

	static string image, filename, name; 
	static json object, spawnData, data;
	static Map* map;
private:
	static int space;
};