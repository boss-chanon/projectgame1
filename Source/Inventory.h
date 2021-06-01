#pragma once

#include "JsonManager.h"
#include "Stack.h"
#include "Item.h"
#include <iostream>

class Inventory
{
public:
	Inventory(string filename, string name, int size);
	~Inventory();

	void load();
	void add(Stack data);
	void clearSlot(int slot);
	void changeSlot(int from, int to);
	int removeBySlot(int order, int figure);
	bool removeByID(string ID);
	void save();

	vector<Stack> item;
private:
	int maxFigure, slotSize;
	json data;
	string file, name;
};