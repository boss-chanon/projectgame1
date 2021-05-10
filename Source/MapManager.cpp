#include "MapManager.h"

string MapManager::image, MapManager::filename, MapManager::name;
json MapManager::object, MapManager::spawnData, MapManager::data;
Map* MapManager::map;

int MapManager::space = 50;

void MapManager::loadData(string fname, string n)
{
	ObjectManager::list.clear();
	ObjectManager::object.clear();

	filename = fname;
	name = n;
	data = JsonManager::loadJson(const_cast<char*>(filename.c_str()));

	image = data[name]["image"];
	object = data[name]["object"];
	spawnData = data[name]["spawnData"];

	ObjectManager::objectLoad(object);

	map = new Map(const_cast<char*>(image.c_str()));
}

void MapManager::spawnObject(const int spawnTime)
{
	vector<int> spawnRange = { 0 };
	vector<spawnArea> area;
	int Max = 0;

	json spawnObj = spawnData["object"];

	for (int i = 0; i < spawnObj.size(); i++)
	{
		int range = spawnObj[to_string(i)]["spawnRate"] + spawnRange[i];
		spawnRange.push_back(range);
		Max = range;

		spawnArea tran;
		tran.height = spawnObj[to_string(i)]["area"]["height"];
		tran.width = spawnObj[to_string(i)]["area"]["width"];
		tran.x = spawnObj[to_string(i)]["area"]["x"];
		tran.y = spawnObj[to_string(i)]["area"]["y"];

		area.push_back(tran);
	}

	if (TimeManager::delay(spawnTime))
	{
		int seed = TimeManager::getTime();

		srand(seed);
		int numRand = rand() % (Max + 1);

		for (int i = 0; i <= spawnRange.size() - 2; i++)
		{
			int xRand = rand() % area[i].width + area[i].x;
			int yRand = rand() % area[i].height + area[i].y;

			ObjectData objData;

			if ((spawnRange[i] <= numRand) && (numRand < spawnRange[i + 1]))
			{
				SDL_Rect objRect;
				string title = to_string(i);
				objRect.h = objData.height = spawnObj[title]["height"];
				objRect.w = objData.width = spawnObj[title]["width"];
				objRect.x = objData.x = xRand;
				objRect.y = objData.y = yRand;
				objData.HP = spawnObj[title]["HP"];
				objData.image = spawnObj[title]["image"];

				if (!spawnOverlab(objRect))
				{
					ObjectManager::add(objData);
					cout << "add" << endl;
				}
			}
		}
	}
}

bool MapManager::spawnOverlab(SDL_Rect rect)
{
	SDL_Rect objRect;

	if (Collision(PlayerPosition::rect, rect))
	{
		return true;
	}

	for (int n = 0; n < ObjectManager::list.size(); n++)
	{
		objRect.h = ObjectManager::list[n].height + (space * 2);
		objRect.w = ObjectManager::list[n].width + (space * 2);
		objRect.x = ObjectManager::list[n].x - space;
		objRect.y = ObjectManager::list[n].y - space;
		if (Collision(objRect, rect))
		{
			return true;
		}
	}
	return false;
}

void MapManager::changeMap(SDL_Rect& rect)
{
	SDL_Rect area;
	area.x = 0;
	area.y = 0;
	area.w = map->width;
	area.h = map->height;

	if (rect.x < area.x) // LEFT
	{
		loadData(filename, data[name]["changeMap"]["LEFT"]);
		rect.x = 0;
		rect.y = 0;
	}
	if (rect.y < area.y) // TOP
	{
		loadData(filename, data[name]["changeMap"]["TOP"]);
		rect.x = 0;
		rect.y = 0;
	}
	if (rect.x + rect.w > area.x + area.w) // RIGHT
	{
		loadData(filename, data[name]["changeMap"]["RIGHT"]);
		rect.x = 0;
		rect.y = 0;
	}
	if (rect.y + rect.h > area.y + area.h) // BUTTOM
	{
		loadData(filename, data[name]["changeMap"]["BUTTOM"]);
		rect.x = 0;
		rect.y = 0;
	}
}

void MapManager::saveData()
{
	data[name]["image"] = image;
	data[name]["object"] = ObjectManager::save();
	data[name]["spawnData"] = spawnData;

	JsonManager::saveJson(data, const_cast<char*>(filename.c_str()));
}