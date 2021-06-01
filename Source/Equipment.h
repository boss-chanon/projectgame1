#pragma once

#include "JsonManager.h"
#include "Inventory.h"
#include "Item.h"
#include "StatManager.h"
#include "Attack.h"
#include "StatManager.h"

class Equipment
{
public:
	Equipment(Inventory* inventory, string filename, string name);
	~Equipment();

	void equip(int order);
	void unequip(string position);
	
	void setStat(Stat userStat);
	void loadStat();
	void equipStat(string ID);
	void unequipStat(string ID);
	
	void loadWeapon();
	void attack(bool click, int x, int y, string direction, int xpos, int ypos, SDL_Point center);

	void render();
	void save();

private:
	Stat stat;
	json slot, data;
	Attack* atk;
	Inventory* inventory;
	string filename, name, damageType;
};