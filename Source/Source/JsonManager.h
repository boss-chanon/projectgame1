#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

class JsonManager
{
public:
	static json loadJson(const char* filename);
	static void saveJson(json data, const char* filename);
};