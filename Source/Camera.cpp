#include "Camera.h"

int Camera::xpos;
int Camera::ypos;

SDL_Point Camera::cen;

SDL_Point Camera::center()
{
	cen.x = Game::width / 2;
	cen.y = Game::height / 2;

	return cen;
}

int Camera::xmove()
{
	xpos += (Player::position.x * Player::speed);
	
	return xpos;
}

int Camera::ymove()
{
	ypos += (Player::position.y * Player::speed);

	return ypos;
}