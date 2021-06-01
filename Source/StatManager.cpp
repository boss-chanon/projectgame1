#include "StatManager.h"

json StatManager::data;
string StatManager::filename;

void StatManager::loadStat(string fname)
{
	filename = fname;
	data = JsonManager::loadJson(const_cast<char*>(filename.c_str()));
}

Stat StatManager::getStat(string name)
{
	Stat stat;
	stat.AGI = data[name]["stat"]["AGI"];
	stat.CHA = data[name]["stat"]["CHA"];
	stat.DEX = data[name]["stat"]["DEX"];
	stat.END = data[name]["stat"]["END"];
	stat.HP = data[name]["stat"]["HP"];
	stat.INT = data[name]["stat"]["INT"];
	stat.MP = data[name]["stat"]["MP"];
	stat.PER = data[name]["stat"]["PER"];
	stat.STR = data[name]["stat"]["STR"];
	stat.WIL = data[name]["stat"]["WIL"];
	stat.WIS = data[name]["stat"]["WIS"];

	return stat;
}

void StatManager::saveStat(string name, Stat stat)
{
	data[name]["stat"]["AGI"] = stat.AGI;
	data[name]["stat"]["CHA"] = stat.CHA;
	data[name]["stat"]["DEX"] = stat.DEX;
	data[name]["stat"]["END"] = stat.END;
	data[name]["stat"]["HP"]= stat.HP;
	data[name]["stat"]["INT"] = stat.INT;
	data[name]["stat"]["MP"] = stat.MP;
	data[name]["stat"]["PER"] = stat.PER;
	data[name]["stat"]["STR"] = stat.STR;
	data[name]["stat"]["WIL"] = stat.WIL;
	data[name]["stat"]["WIS"] = stat.WIS;

	JsonManager::saveJson(data, const_cast<char*>(filename.c_str()));
}

Stat StatManager::addStat(Stat a, Stat b)
{
	Stat c;
	c.AGI = a.AGI + b.AGI;
	c.CHA = a.CHA + b.CHA;
	c.DEX = a.DEX + b.DEX;
	c.END = a.END + b.END;
	c.HP = a.HP + b.HP;
	c.INT = a.INT + b.INT;
	c.MP = a.MP + b.MP;
	c.PER = a.PER + b.PER;
	c.STR = a.STR + b.STR;
	c.WIL = a.WIL + b.WIL;
	c.WIS = a.WIS + b.WIS;
	
	return c;
}