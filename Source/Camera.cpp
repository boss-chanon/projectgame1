#include "Camera.h"

int Camera::xmove, Camera::ymove;

void Camera::move(SDL_Point position, int speed)
{
	xmove += (position.x * speed);
	ymove += (position.y * speed);
}

SDL_Point Camera::center()
{
	SDL_Point cen;
	cen.x = Game::width / 2;
	cen.y = Game::height / 2;

	return cen;
}