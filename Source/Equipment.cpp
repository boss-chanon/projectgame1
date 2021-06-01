#include "Equipment.h"

Equipment::Equipment(Inventory* inven, string fname, string n)
{
	filename = fname;
	name = n;
	inventory = inven;

	data = JsonManager::loadJson(const_cast<char*>(filename.c_str()));
	slot = data[name]["equipment"];

	loadStat();
	loadWeapon();
}

void Equipment::equip(int order)
{
	string ID = inventory->item[order].ID;

	if (ID != "0")
	{
		string type = Item::getData(ID)["type"];
		string position = Item::getData(ID)["position"];
		
		if (type == "equipment")
		{	
			if (slot[position] != "none")
			{
				unequip(position);
			}
			inventory->removeBySlot(order, 1);
			slot[position] = ID;
			equipStat(ID);
			save();

			if (position == "weapon")
			{
				SDL_Point radius, area;
				string image = Item::getData(ID)["image"];
				int speed = Item::getData(ID)["speed"];
				area.x = Item::getData(ID)["hitArea"]["sizeX"];
				area.y = Item::getData(ID)["hitArea"]["sizeY"];
				radius.x = (area.x - 64) / 2;
				radius.y = Item::getData(ID)["hitArea"]["radius"];

				atk = new Attack(const_cast<char*>(image.c_str()), area, speed, radius);

				damageType = Item::getData(ID)["damageType"];
			}
		}
	}
}

void Equipment::unequip(string position)
{
	if (slot[position] != "none")
	{
		inventory->add(Stack(slot[position], 1));
		unequipStat(slot[position]);
		slot[position] = "none";

		if (position == "weapon")
		{
			string image;
			SDL_Point area, radius;
			int speed;

			speed = 3;
			image = "../image/testATK.png";
			area.x = area.y = 16;
			radius.y = 0;
			radius.x = (area.x - 64) / 2;

			atk = new Attack(const_cast<char*>(image.c_str()), area, speed, radius);

			damageType = "none";
		}
	}

	save();
}

void Equipment::setStat(Stat userStat)
{
	Stat totalStat = StatManager::addStat(stat, userStat);
	atk->setStat(totalStat);
}

void Equipment::loadStat()
{
	if (slot["arm"] != "none")
	{
		equipStat(slot["arm"]);
	}
	if (slot["body"] != "none")
	{
		equipStat(slot["body"]);
	}
	if (slot["cloth"] != "none")
	{
		equipStat(slot["cloth"]);
	}
	if (slot["foot"] != "none")
	{
		equipStat(slot["foot"]);
	}
	if (slot["head"] != "none")
	{
		equipStat(slot["head"]);
	}
	if (slot["leg"] != "none")
	{
		equipStat(slot["leg"]);
	}
	if (slot["weapon"] != "none")
	{
		equipStat(slot["weapon"]);
	}
}

void Equipment::equipStat(string ID)
{
	stat.AGI += Item::getData(ID)["stat"]["AGI"];
	stat.CHA += Item::getData(ID)["stat"]["CHA"];
	stat.DEX += Item::getData(ID)["stat"]["DEX"];
	stat.END += Item::getData(ID)["stat"]["END"];
	stat.HP += Item::getData(ID)["stat"]["HP"];
	stat.INT += Item::getData(ID)["stat"]["INT"];
	stat.MP += Item::getData(ID)["stat"]["MP"];
	stat.PER += Item::getData(ID)["stat"]["PER"];
	stat.STR += Item::getData(ID)["stat"]["STR"];
	stat.WIL += Item::getData(ID)["stat"]["WIL"];
	stat.WIS += Item::getData(ID)["stat"]["WIS"];
}

void Equipment::unequipStat(string ID)
{
	stat.AGI -= Item::getData(ID)["stat"]["AGI"];
	stat.CHA -= Item::getData(ID)["stat"]["CHA"];
	stat.DEX -= Item::getData(ID)["stat"]["DEX"];
	stat.END -= Item::getData(ID)["stat"]["END"];
	stat.HP -= Item::getData(ID)["stat"]["HP"];
	stat.INT -= Item::getData(ID)["stat"]["INT"];
	stat.MP -= Item::getData(ID)["stat"]["MP"];
	stat.PER -= Item::getData(ID)["stat"]["PER"];
	stat.STR -= Item::getData(ID)["stat"]["STR"];
	stat.WIL -= Item::getData(ID)["stat"]["WIL"];
	stat.WIS -= Item::getData(ID)["stat"]["WIS"];
}

void Equipment::loadWeapon()
{
	string ID = slot["weapon"];
	string image;
	SDL_Point area, radius;
	int speed;

	if (ID == "none")
	{
		speed = 3;
		image = "../image/testATK.png";
		area.x = area.y = 16;
		radius.y = 0;
		radius.x = (area.x - 64) / 2;

		atk = new Attack(const_cast<char*>(image.c_str()), area, speed, radius);

		damageType = "none";
	}

	else
	{
		image = Item::getData(ID)["image"];
		speed = Item::getData(ID)["speed"];
		area.x = Item::getData(ID)["hitArea"]["sizeX"];
		area.y = Item::getData(ID)["hitArea"]["sizeY"];
		radius.x = (area.x - 64) / 2;
		radius.y = Item::getData(ID)["hitArea"]["radius"];

		atk = new Attack(const_cast<char*>(image.c_str()), area, speed, radius);

		damageType = Item::getData(ID)["damageType"];
	}
}

void Equipment::attack(bool click, int x, int y, string direction, int xpos, int ypos, SDL_Point center)
{
	if (damageType == "none")
	{
		atk->blunt(click, direction, xpos, ypos, center);
	}
	if (damageType == "slash")
	{
		atk->slash(click, direction, xpos, ypos, center);
	}
	if (damageType == "blunt")
	{
		atk->blunt(click, direction, xpos, ypos, center);
	}
	if (damageType == "pierce")
	{
		atk->pierce(click, direction, xpos, ypos, center);
	}
	if (damageType == "shoot")
	{
		atk->shoot(click, x, y, xpos, ypos, center);
	}
}

void Equipment::render()
{
	atk->render();
}

void Equipment::save()
{
	data[name]["equipment"] = slot;
	JsonManager::saveJson(data, const_cast<char*>(filename.c_str()));
}