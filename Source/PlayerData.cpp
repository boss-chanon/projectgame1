#include "PlayerData.h"

string PlayerData::ID, PlayerData::image, PlayerData::password, PlayerData::map;
SDL_Point PlayerData::position;
json PlayerData::data;

bool PlayerData::login(string id, string pass)
{
	data = JsonManager::loadJson(const_cast<char*>(GameSetting::playerData.c_str()));

	ID = id;
	password = pass;

	if (data[ID].is_null()) {
		return false;
	}

	if (data[ID]["password"] != password)
	{
		return false;
	}
	return true;
}

void PlayerData::load()
{
	image = data[ID]["image"];
	map = data[ID]["loacation"]["map"];
	position.x = data[ID]["loacation"]["positionX"];
	position.y = data[ID]["loacation"]["positionY"];
}

void PlayerData::save()
{
	data[ID]["image"] = image;
	data[ID]["loacation"]["map"] = MapManager::name;
	data[ID]["loacation"]["positionX"] = PlayerPosition::rect.x;
	data[ID]["loacation"]["positionY"] = PlayerPosition::rect.y;

	JsonManager::saveJson(data, GameSetting::playerData.c_str());
}