#include "MapManager.h"

string MapManager::image, MapManager::filename, MapManager::name;
json MapManager::object, MapManager::spawnData, MapManager::data;
Map* MapManager::map;

int MapManager::seed = SDL_GetTicks();
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

void MapManager::spawn(const int spawnTime)
{
	vector<int> spawnRange = { 0 };
	vector<spawnArea> area;
	int Max;

	for (int i = 0; i < spawnData.size(); i++)
	{
		int range = spawnData[to_string(i)]["spawnRate"] + spawnRange[i];
		spawnRange.push_back(range);
		Max = range;

		spawnArea tran;
		tran.height = spawnData[to_string(i)]["area"]["height"];
		tran.width = spawnData[to_string(i)]["area"]["width"];
		tran.x = spawnData[to_string(i)]["area"]["x"];
		tran.y = spawnData[to_string(i)]["area"]["y"];

		area.push_back(tran);
	}

	if (TimeManager::delay(spawnTime))
	{
		srand(SDL_GetTicks());
		bool addStage = true;
		int numRand = rand() % (Max + 1);

		for (int i = 0; i <= spawnRange.size() - 2; i++)
		{
			int xRand = rand() % area[i].width + area[i].x;
			int yRand = rand() % area[i].height + area[i].y;

			if (spawnRange[i] <= numRand < spawnRange[i + 1])
			{
				ObjectData objData;
				SDL_Rect objRect, baseRect;
				string title = to_string(i);
				objRect.h = objData.height = spawnData[title]["height"];
				objRect.w = objData.width = spawnData[title]["width"];
				objRect.x = objData.x = xRand;
				objRect.y = objData.y = yRand;
				objData.HP = spawnData[title]["HP"];
				objData.image = spawnData[title]["image"];

				for (int n = 0; n < ObjectManager::list.size(); n++)
				{
					baseRect.h = ObjectManager::list[n].height;
					baseRect.w = ObjectManager::list[n].width;
					baseRect.x = ObjectManager::list[n].x + space;
					baseRect.y = ObjectManager::list[n].y + space;
					if (Collision(baseRect, objRect))
					{
						addStage = false;
					}
				}
				if (addStage)
				{
					ObjectManager::add(objData);
					cout << "add" << endl;
				}
			}
		}
	}
}

void MapManager::saveData()
{
	data;

	data[name]["image"] = image;
	data[name]["object"] = ObjectManager::save();
	data[name]["spawnData"] = spawnData;

	JsonManager::saveJson(data, const_cast<char*>(filename.c_str()));
}