#pragma once

#include <string>

using namespace std;

struct Stack
{
	string ID;
	int figure;

	Stack(string id, int fig)
	{
		ID = id;
		figure = fig;
	}
};