#include "JsonManager.h"

json JsonManager::loadJson(const char* filename)
{
	ifstream file(filename);
	json data = json::parse(file);

	return data;
}

/*void JsonManager::saveJson(json data, const char* filename)
{
	/*ofstream file(filename);
	file << std::setw(4) << data << endl; // don't sure
}*/