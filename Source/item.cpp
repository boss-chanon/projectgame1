#include "Item.h"

json Item::data;

void Item::loadItem(string filename)
{
	data = JsonManager::loadJson(const_cast<char*>(filename.c_str()));
}

json Item::getData(string ID)
{
	return data[ID];
}