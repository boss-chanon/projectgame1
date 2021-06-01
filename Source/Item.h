#pragma once

#include "JsonManager.h"

class Item
{
public:
	static void loadItem(string filename);
	static json getData(string ID);
private:
	static json data;
};