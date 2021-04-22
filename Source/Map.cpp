#include "Map.h"

Map::Map(const char* filename, int w, int h)
{
	texture = TextManager::LoadTexture(filename);

	width = w;
	height = h;
}

Map::~Map()
{}

void Map::loadMap()
{
	srcRect.w = Game::width;
	srcRect.h = Game::height;
	srcRect.x = Camera::xmove();
	srcRect.y = Camera::ymove();

	destRect.w = Game::width;
	destRect.h = Game::height;
	destRect.x = destRect.y = 0;
}

void Map::drawMap()
{
	TextManager::Draw(texture, srcRect, destRect);
}