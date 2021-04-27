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

private:
	static vector<GameObject> object;
	static ObjectData tran;
	static json data, none;

	static string title;
	static int r, value, i;
};