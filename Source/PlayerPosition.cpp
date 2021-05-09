#include "PlayerPosition.h"
#include "JsonManager.h"

int PlayerPosition::height, PlayerPosition::width, PlayerPosition::xpos, PlayerPosition::ypos;

void PlayerPosition::sizeSet(int w, int h)
{
	width = w;
	height = h;
}

void PlayerPosition::move(SDL_Point position, int speed)
{
	xpos += (position.x * speed);
	ypos += (position.y * speed);

	Camera::set(xpos, ypos);
}

SDL_Rect PlayerPosition::getPosition()
{
	SDL_Rect rect;
	rect.w = width;
	rect.h = height;
	rect.x = xpos;
	rect.y = ypos;

	return rect;
}

void PlayerPosition::setPosition(int x, int y)
{
	xpos = x;
	ypos = y;

	Camera::set(xpos, ypos);
}