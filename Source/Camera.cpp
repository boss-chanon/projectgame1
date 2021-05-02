#include "Camera.h"

int Camera::xpos, Camera::ypos, Camera::speed;
SDL_Point Camera::cen, Camera::position;

void Camera::move(SDL_Point pos, int s)
{
	position = pos;
	speed = s;
}

SDL_Point Camera::center()
{
	cen.x = Game::width / 2;
	cen.y = Game::height / 2;

	return cen;
}

int Camera::xmove()
{
	xpos += (position.x * speed);
	
	return xpos;
}

int Camera::ymove()
{
	ypos += (position.y * speed);

	return ypos;
}