#include "GameSetting.h"

string GameSetting::equipment, GameSetting::inventory, GameSetting::item, GameSetting::map, GameSetting::stat, GameSetting::playerData;
int GameSetting::width, GameSetting::height, GameSetting::widthSTD, GameSetting::heightSTD, GameSetting::CharactorStdWidth, GameSetting::CharactorStdHeight;
double GameSetting::scaleX, GameSetting::scaleY;

void GameSetting::load(const char* filename)
{
	json data = JsonManager::loadJson(filename);

	equipment = data["file"]["equipment"];
	inventory = data["file"]["inventory"];
	item = data["file"]["item"];
	map = data["file"]["map"];
	stat = data["file"]["stat"];
	playerData = data["file"]["playerData"];

	widthSTD = data["width"];
	heightSTD = data["height"];

	CharactorStdHeight = data["charator"]["height"];
	CharactorStdWidth = data["charator"]["width"];
}

void GameSetting::setSize(int w, int h)
{
	width = w;
	height = h;

	scaleX = (double)width / (double)widthSTD;
	scaleY = (double)height / (double)heightSTD;
}

SDL_Point GameSetting::charactorSize()
{
	SDL_Point size;
	size.x = CharactorStdWidth * scaleX;
	size.y = CharactorStdHeight * scaleY;

	return size;
}