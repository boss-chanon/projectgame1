#include "StatManager.h"

Stat StatManager::loadStat(const char* filename, string name)
{
	json data = JsonManager::loadJson(filename);
	
	Stat stat;
	stat.AGI = data[name]["AGI"];
	stat.CHA = data[name]["CHA"];
	stat.DEX = data[name]["DEX"];
	stat.END = data[name]["END"];
	stat.HP = data[name]["HP"];
	stat.INT = data[name]["INT"];
	stat.MP = data[name]["MP"];
	stat.PER = data[name]["PER"];
	stat.STR = data[name]["STR"];
	stat.WIL = data[name]["WIL"];
	stat.WIS = data[name]["WIS"];

	return stat;
}

void StatManager::saveStat(const char* filename, string name, Stat stat)
{
	json data;
	data[name]["AGI"] = stat.AGI;
	data[name]["CHA"] = stat.CHA;
	data[name]["DEX"] = stat.DEX;
	data[name]["END"] = stat.END;
	data[name]["HP"]= stat.HP;
	data[name]["INT"] = stat.INT;
	data[name]["MP"] = stat.MP;
	data[name]["PER"] = stat.PER;
	data[name]["STR"] = stat.STR;
	data[name]["WIL"] = stat.WIL;
	data[name]["WIS"] = stat.WIS;

	JsonManager::saveJson(data, filename);
}