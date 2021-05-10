#include "Camera.h"

int Camera::xcam, Camera::ycam;

SDL_Point Camera::center()
{
	SDL_Point cen;
	cen.x = Game::width / 2;
	cen.y = Game::height / 2;

	return cen;
}

void Camera::set(int x, int y)
{
	xcam = x - center().x + (PlayerPosition::rect.w / 2);
	ycam = y - center().y + (PlayerPosition::rect.h / 2);
}