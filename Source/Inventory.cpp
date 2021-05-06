#include "Inventory.h"

Inventory::Inventory(string filename, string n, int size)
{
	file = filename;
	name = n;
	slotSize = size;

	for (int i = 0; i < slotSize; i++)
	{
		item.push_back(Stack("0", 0));
	}

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
		for (int i = 0; i < item.size(); i++)
		{
			if (item[i].ID == "0")
			{
				item[i].ID = data.ID;
				item[i].figure = data.figure;
				break;
			}
		}
	}
}

void Inventory::clearSlot(int slot)
{
	item[slot].ID = "0";
	item[slot].figure = 0;
}

void Inventory::changeSlot(int from, int to)
{
	if (item[to].ID == "0")
	{
		item[to] = item[from];
		clearSlot(from);
	}
}

int Inventory::removeBySlot(int order, int figure)
{
	int over = 0;

	item[order].figure -= figure;

	if (item[order].figure <= 0)
	{
		over -= item[order].figure;
		clearSlot(order);
	}

	return over;
}

bool Inventory::removeByID(string ID)
{
	for (int i = slotSize - 1; i >= 0; i--)
	{
		if (item[i].ID == ID)
		{
			if (item[i].figure > 0)
			{
				item[i].figure--;
				if (item[i].figure <= 0)
				{
					clearSlot(i);
				}
				return true;
			}
		}
	}

	return false;
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