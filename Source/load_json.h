#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

void load_json(nlohmann::json& path, const char* filename) {
	std::ifstream json_file(filename);
	nlohmann::json read_data = nlohmann::json::parse(json_file);
	path = read_data;
}