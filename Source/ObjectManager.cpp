#include "ObjectManager.h"

vector<GameObject> ObjectManager::object;
vector<ObjectData> ObjectManager::list;
int ObjectManager::value;

void ObjectManager::objectLoad(json data)
{
	ObjectData tran;

	for (int i = 0; i < data.size(); i++)
	{
		string title = to_string(i);

		tran.image = data[title]["image"];
		tran.width = data[title]["width"];
		tran.height = data[title]["height"];
		tran.x = data[title]["x"];
		tran.y = data[title]["y"];
		tran.HP = data[title]["HP"];
		tran.Element = data[title]["element"];

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

json ObjectManager::save()
{
	json data;

	for (int i = 0; i < value; i++)
	{
		string title = to_string(i);

		data[title]["image"] = list[i].image;
		data[title]["width"] = list[i].width;
		data[title]["height"] = list[i].height;
		data[title]["x"] = list[i].x;
		data[title]["y"] = list[i].y;
		data[title]["HP"] = list[i].HP;
		data[title]["element"] = list[i].Element;
	}

	return data;
}

void ObjectManager::remove(int order)
{
	list.erase(list.begin() + order);
	object.erase(object.begin() + order);
}