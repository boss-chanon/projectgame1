#pragma once

#include "Map.h"
#include "JsonManager.h"
#include "ObjectManager.h"
#include "TimeManager.h"
#include "SpawnArea.h"
#include <stdlib.h>

class MapManager
{
public:
	static void loadData(string filename, string name);
	static void spawn(const int spawnTime);
	static void saveData();

	static string image, filename, name; 
	static json object, spawnData, data;
	static Map* map;
private:
	static int seed;
	static int space;
};