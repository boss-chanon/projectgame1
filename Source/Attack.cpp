#include "Attack.h"
#include "ObjectManager.h"

Attack::Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad)
{
	texture = TextManager::LoadTexture(filename);

	speed = spd;
	area = size;
	radius = rad;
}

void Attack::setStat(Stat s)
{
	stat = s;
}

void Attack::slash(std::string direction, int posx, int posy, SDL_Point cen)
{
	xpos = posx;
	ypos = posy;
	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;

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
			for (int i = 0; i < ObjectManager::list.size(); i++)
			{
				objRect.x = ObjectManager::list[i].x - Camera::xmove();
				objRect.y = ObjectManager::list[i].y - Camera::ymove();
				objRect.h = ObjectManager::list[i].height;
				objRect.w = ObjectManager::list[i].width;
				if (Collision(hitRect, objRect))
				{
					cout << "hit" << endl;
					ObjectManager::list[i].HP -= stat.STR;
					if (ObjectManager::list[i].HP == 0)
					{
						ObjectManager::remove(i);
					}
				}
			}
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
}

void Attack::pierce(std::string direction, int posx, int posy, SDL_Point cen)
{
	xpos = posx;
	ypos = posy;
	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;

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
			for (int i = 0; i < ObjectManager::list.size(); i++)
			{
				objRect.x = ObjectManager::list[i].x - Camera::xmove();
				objRect.y = ObjectManager::list[i].y - Camera::ymove();
				objRect.h = ObjectManager::list[i].height;
				objRect.w = ObjectManager::list[i].width;
				if (Collision(hitRect, objRect))
				{
					cout << "hit" << endl;
					ObjectManager::list[i].HP -= stat.STR;
					if (ObjectManager::list[i].HP == 0)
					{
						ObjectManager::remove(i);
					}
				}
			}
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
}

void Attack::blunt(std::string direction, int posx, int posy, SDL_Point cen)
{
	xpos = posx;
	ypos = posy;

	center.x = cen.x + radius.x;
	center.y = cen.y + radius.y + area.y;

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
			for (int i = 0; i < ObjectManager::list.size(); i++)
			{
				objRect.x = ObjectManager::list[i].x - Camera::xmove();
				objRect.y = ObjectManager::list[i].y - Camera::ymove();
				objRect.h = ObjectManager::list[i].height;
				objRect.w = ObjectManager::list[i].width;
				if (Collision(hitRect, objRect))
				{
					cout << "hit" << endl;
					ObjectManager::list[i].HP -= stat.STR;
					if (ObjectManager::list[i].HP == 0)
					{
						ObjectManager::remove(i);
					}
				}
			}
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
}

void Attack::shoot(std::string direction, int posx, int posy, SDL_Point cen)
{
	xpos = posx;
	ypos = posy;

	center.x = area.x / 2;
	center.y = area.y / 2 + move;

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
		xmove += speed * sin(angle * PI / 180);
		ymove += speed * cos(angle * PI / 180);
		if (move >= sqrt(pow(x - destRect.x - center.x, 2) + pow(destRect.y + center.y - y, 2)))
		{
			xmove = ymove = move = 0;
			ATKstage = false;
		}

		hitRect.w = area.x;
		hitRect.h = area.x;
		hitRect.x = xpos - radius.x + xmove;
		hitRect.y = ypos - radius.x - ymove;

		for (int i = 0; i < ObjectManager::list.size(); i++)
		{
			objRect.x = ObjectManager::list[i].x - Camera::xmove();
			objRect.y = ObjectManager::list[i].y - Camera::ymove();
			objRect.h = ObjectManager::list[i].height;
			objRect.w = ObjectManager::list[i].width;
			if (Collision(hitRect, objRect))
			{
				cout << "hit" << endl;
				xmove = ymove = move = 0;
				ATKstage = false;
				ObjectManager::list[i].HP -= stat.STR;
				if (ObjectManager::list[i].HP <= 0)
				{
					ObjectManager::remove(i);
				}
			}
		}
	}	

	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = aniX;
	srcRect.y = aniY;

	destRect.w = area.x;
	destRect.h = area.y;
	destRect.x = xpos - radius.x;
	destRect.y = ypos + cen.y - (area.y / 2) - move;
}

void Attack::attackDirection(std::string direction)
{
	if (direction == "Top")
	{
		angle = 0;
		hitRect.w = area.x;
		hitRect.h = area.y;
		hitRect.x = xpos - radius.x;
		hitRect.y = ypos - radius.y - area.y;
	}
	if (direction == "Left")
	{
		angle = 270;
		hitRect.w = area.y;
		hitRect.h = area.x;
		hitRect.x = xpos - area.y - radius.y;
		hitRect.y = ypos - radius.x;
	}
	if (direction == "Buttom")
	{
		angle = 180;
		hitRect.w = area.x;
		hitRect.h = area.y;
		hitRect.x = xpos - radius.x;
		hitRect.y = ypos - radius.y - area.y + (center.y * 2) - area.y;
	}
	if (direction == "Right")
	{
		angle = 90;
		hitRect.w = area.y;
		hitRect.h = area.x;
		hitRect.x = xpos - area.y - radius.y + (center.y * 2) - area.y;
		hitRect.y = ypos - radius.x;
	}
}

void Attack::render()
{
	if (ATKstage) 
	{
		TextManager::RotateDraw(texture, srcRect, destRect, angle, center);
	}
}