#include "MapManager.h"

string MapManager::image, MapManager::filename, MapManager::name;
json MapManager::object, MapManager::spawnData, MapManager::data;
Map* MapManager::map;

int MapManager::space = 50;

void MapManager::loadData(string fname, string n)
{
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
	int Max;

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
		int seed = SDL_GetTicks();

		srand(seed);
		int numRand = rand() % (Max + 1);

		for (int i = 0; i <= spawnRange.size() - 2; i++)
		{
			int xRand = rand() % area[i].width + area[i].x;
			int yRand = rand() % area[i].height + area[i].y;

			if (spawnRange[i] <= numRand < spawnRange[i + 1])
			{
				ObjectData objData;
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
	SDL_Rect playerRect;

	playerRect.w = 64;
	playerRect.h = 64;
	playerRect.x = Camera::xmove + Camera::center().x - (playerRect.w / 2);
	playerRect.y = Camera::ymove + Camera::center().y - (playerRect.h / 2);

	if (Collision(playerRect, rect))
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

void MapManager::saveData()
{
	data;

	data[name]["image"] = image;
	data[name]["object"] = ObjectManager::save();
	data[name]["spawnData"] = spawnData;

	JsonManager::saveJson(data, const_cast<char*>(filename.c_str()));
}