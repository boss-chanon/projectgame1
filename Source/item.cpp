#include "Item.h"

json Item::data;

void Item::loadItem(const char* filename)
{
	data = JsonManager::loadJson(filename);
}

json Item::getData(string ID)
{
	return data[ID];
}