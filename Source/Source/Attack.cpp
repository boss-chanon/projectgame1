#include "Attack.h"

Attack::Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad)
{
	texture = TextManager::LoadTexture(filename);

	speed = spd;
	area = size;
	radius = rad;
}

void Attack::slash(std::string direction, int xpos, int ypos, SDL_Point cen)
{
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
		aniY = 20;
		if (aniX >= 60)
		{
			aniX = 0;
			ATKstage = false;
		}
	}

	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = aniX;
	srcRect.y = aniY;

	destRect.w = area.x;
	destRect.h = area.y;
	destRect.x = xpos - radius.x;
	destRect.y = ypos - radius.y - area.y;
	
	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;
}

void Attack::pierce(std::string direction, int xpos, int ypos, SDL_Point cen)
{
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
		aniX = 20;
		aniY += speed;
		if (aniY >= 60)
		{
			aniY = 0;
			ATKstage = false;
		}
	}

	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = aniX;
	srcRect.y = aniY;

	destRect.w = area.x;
	destRect.h = area.y;
	destRect.x = xpos - radius.x;
	destRect.y = ypos - radius.y - area.y;

	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;
}

void Attack::blunt(std::string direction, int xpos, int ypos, SDL_Point cen)
{
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
		aniX = 20;
		aniY += speed;
		if (aniY >= 60)
		{
			aniY = 0;
			ATKstage = false;
		}
	}

	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = aniX;
	srcRect.y = aniY;

	destRect.w = area.x;
	destRect.h = area.y;
	destRect.x = xpos - radius.x;
	destRect.y = ypos - radius.y - area.y;

	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;
}

void Attack::shoot(std::string direction, int xpos, int ypos, SDL_Point cen)
{

	
	if (!ATKstage)
	{
		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			ATKstage = true;
			angle = atan2((x - destRect.x - center.x) , (destRect.y + center.y - y)) * 180 / PI;
		}
	}

	if (ATKstage)
	{
		aniX = 20;
		aniY = 20;
		move += speed;
		if (move >= sqrt(pow(x - destRect.x - center.x, 2) + pow(destRect.y + center.y - y, 2)))
		{
			move = 0;
			ATKstage = false;
		}
	}	

	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = aniX;
	srcRect.y = aniY;

	destRect.w = area.x;
	destRect.h = area.y;
	destRect.x = xpos - radius.x;
	destRect.y = ypos - radius.y - area.y - move;

	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y + move;
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
	if (ATKstage) 
	{
		TextManager::RotateDraw(texture, srcRect, destRect, angle, center);
	}
	
}