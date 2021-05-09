#include "Map.h"

Map::Map(const char* filename)
{
	texture = TextManager::LoadTexture(filename);

	width = TextManager::width;
	height = TextManager::height;
}

void Map::loadMap()
{
	srcRect.w = Game::width;
	srcRect.h = Game::height;
	srcRect.x = Camera::xcam;
	srcRect.y = Camera::ycam;

	destRect.w = Game::width;
	destRect.h = Game::height;
	destRect.x = destRect.y = 0;
}

void Map::drawMap()
{
	TextManager::Draw(texture, srcRect, destRect);
}