#include "PlayerPosition.h"
#include "MapManager.h"

SDL_Rect PlayerPosition::rect;

void PlayerPosition::sizeSet(int w, int h)
{
	rect.w = w;
	rect.h = h;
}

void PlayerPosition::move(SDL_Point position, int speed)
{
	rect.x += (position.x * speed);
	rect.y += (position.y * speed);

	Camera::set(rect.x, rect.y);
	MapManager::changeMap(rect);
}

void PlayerPosition::setPosition(int x, int y)
{
	rect.x = x;
	rect.y = y;

	Camera::set(rect.x, rect.y);
}