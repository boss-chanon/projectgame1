#include "Attack.h"

Attack::Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad)
{
	texture = TextManager::LoadTexture(filename);

	speed = spd;
	area = size;
	radius = rad;
}

void Attack::attack(std::string direction, int xpos, int ypos, SDL_Point cen)
{
	SDL_PumpEvents();
	if (!ATKstage)
	{
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			ATKstage = true;
			attackDirection(direction);
		}
	}


	if (ATKstage)
	{
		aniX += speed;
		if (aniX >= 40)
		{
			aniX = 0;
			ATKstage = false;
		}

	}

	srcRect.w = 40;
	srcRect.h = 16;
	srcRect.x = aniX;
	srcRect.y = aniY;

	destRect.w = area.x;
	destRect.h = area.y;
	destRect.x = xpos - radius.x;
	destRect.y = ypos - radius.y - area.y;

	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;
}

void Attack::attackDirection(std::string direction)
{
	if (direction == "Top")
	{
		angle = 0;
	}
	if (direction == "Left")
	{
		angle = 270;
	}
	if (direction == "Buttom")
	{
		angle = 180;
	}
	if (direction == "Right")
	{
		angle = 90;
	}
}

void Attack::render()
{
	TextManager::RotateDraw(texture, srcRect, destRect, angle, center);
}