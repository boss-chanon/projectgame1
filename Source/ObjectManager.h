#pragma once

#include "GameObject.h"
#include "JsonManager.h"
#include <vector>
#include "ObjectData.h"

class ObjectManager
{
public:
	static void objectLoad(const char* filename);
	static void update();
	static void render();
	static void add(ObjectData addData);
	static void save(const char* filename);
	static void remove(int order);
	
	static vector<GameObject> object;
	static vector<ObjectData> list;
private:
	static ObjectData tran;
	static json data, none;

	static string title;
	static int value, i;
};