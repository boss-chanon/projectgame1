#include "ObjectManager.h"

vector<GameObject> ObjectManager::object;
vector<ObjectData> ObjectManager::list;
int ObjectManager::value;

void ObjectManager::objectLoad(const char* filename)
{
	json data = JsonManager::loadJson(filename);

	ObjectData tran;

	for (int i = 0; i < data.size(); i++)
	{
		string title = to_string(i);

		tran.filename = data[title]["filename"];
		tran.width = data[title]["width"];
		tran.height = data[title]["height"];
		tran.x = data[title]["x"];
		tran.y = data[title]["y"];
		tran.HP = data[title]["HP"];

		add(tran);
	}
}

void ObjectManager::update()
{
	value = object.size();

	for (int i = 0; i < value; i++)
	{
		object[i].update();
	}
}

void ObjectManager::render()
{
	for (int i = 0; i < value; i++)
	{
		object[i].render();
	}
}

void ObjectManager::add(ObjectData addData)
{
	list.push_back(addData);
	object.push_back(GameObject::GameObject(addData));
}

void ObjectManager::save(const char* filename)
{
	json data;

	for (int i = 0; i < value; i++)
	{
		string title = to_string(i);

		data[title]["filename"] = list[i].filename;
		data[title]["width"] = list[i].width;
		data[title]["height"] = list[i].height;
		data[title]["x"] = list[i].x;
		data[title]["y"] = list[i].y;
		data[title]["HP"] = list[i].HP;
	}

	JsonManager::saveJson(data, filename);
}

void ObjectManager::remove(int order)
{
	list.erase(list.begin() + order);
	object.erase(object.begin() + order);
}