#pragma once

#include "Stat.h"
#include "JsonManager.h"

class StatManager
{
public:
	static void loadStat(string filename);
	static Stat getStat(string name);
	static void saveStat(string name, Stat stat);
	static Stat addStat(Stat a, Stat b);
private:
	static json data;
	static string filename;
};