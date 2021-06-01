#include "JsonManager.h"
#include <iostream>

json JsonManager::loadJson(const char* filename)
{
	ifstream file(filename);
	json data = json::parse(file);

	return data;
}

void JsonManager::saveJson(json data, const char* filename)
{
	ofstream file(filename);
	file << setw(1) << data << endl;
}