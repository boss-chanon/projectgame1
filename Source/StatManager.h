#pragma once

#include "Stat.h"
#include "JsonManager.h"

class StatManager
{
public:
	static Stat loadStat(const char* filename, string name);
	static void saveStat(const char* filename, string name, Stat stat);
};