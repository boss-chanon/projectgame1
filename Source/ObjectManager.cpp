#include "ObjectManager.h"

vector<GameObject> ObjectManager::object;
ObjectData ObjectManager::tran;
json ObjectManager::data, ObjectManager::none;

string ObjectManager::title;
int ObjectManager::r, ObjectManager::value, ObjectManager::i;

void ObjectManager::objectLoad(const char* filename)
{
	int r = 0;
	json data = JsonManager::loadJson(filename);

	ObjectData tran;

	json none = data["NONE"];
	while (data[to_string(r)] != none)
	{
		string title = to_string(r);
		tran.filename = data[title]["filename"];
		tran.width = data[title]["width"];
		tran.height = data[title]["height"];
		tran.x = data[title]["x"];
		tran.y = data[title]["y"];

		object.push_back(GameObject::GameObject(tran));

		r++;
	}
	
	value = object.size();
}

void ObjectManager::update()
{
	for (i = 0; i != value; i++)
	{
		object[i].update();
	}
}

void ObjectManager::render()
{
	for (i = 0; i != value; i++)
	{
		object[i].render();
	}
}