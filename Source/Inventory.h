#pragma once

#include "JsonManager.h"
#include "Stack.h"
#include "Item.h"
#include <iostream>

class Inventory
{
public:
	Inventory(string filename, string name);
	~Inventory();

	void load();
	void add(Stack data);
	int remove(int order, int figure);
	void save();
private:
	vector<Stack> item;
	int maxFigure;
	json data;
	string file, name;
};