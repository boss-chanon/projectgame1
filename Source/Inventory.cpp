#include "Inventory.h"

Inventory::Inventory(string filename, string n)
{
	file = filename;
	name = n;

	maxFigure = 64;
}

Inventory::~Inventory()
{}

void Inventory::load()
{
	data = JsonManager::loadJson(const_cast<char*>(file.c_str()));

	for (int i = 0; i < data[name].size(); i++) 
	{
		string n = to_string(i);
		add(Stack(data[name][n]["ID"], data[name][n]["figure"]));
	}
}

void Inventory::add(Stack data)
{
	bool addStage = false;

	for (int i = 0; i < item.size(); i++)
	{
		if ((data.ID == item[i].ID) && (item[i].figure < maxFigure))
		{
			item[i].figure++;
			addStage = true;
			break;
		}
	}

	if (!addStage)
	{
		item.push_back(data);
	}
}

int Inventory::remove(int order, int figure)
{
	int over = 0;

	item[order].figure -= figure;

	if (item[order].figure <= 0)
	{
		over -= item[order].figure;
		item.erase(item.begin() + order);
	}

	return over;
}

void Inventory::save()
{
	for (int i = 0; i < item.size(); i++)
	{
		string n = to_string(i);

		data[name][n]["ID"] = item[i].ID;
		data[name][n]["figure"] = item[i].figure;
	}

	JsonManager::saveJson(data, const_cast<char*>(file.c_str()));
}