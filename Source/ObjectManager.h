#pragma once

#include "GameObject.h"
#include "JsonManager.h"
#include <vector>
#include "ObjectData.h"

class ObjectManager
{
public:
	static void objectLoad(json data);
	static void update();
	static void render();
	static void add(ObjectData addData);
	static json save();
	static void remove(int order);
	
	static vector<GameObject> object;
	static vector<ObjectData> list;
private:
	static ObjectData tran;

	static string title;
	static int value, i;
};