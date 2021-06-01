#include "Attack.h"
#include "ObjectManager.h"

Attack::Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad)
{
	texture = TextManager::LoadTexture(filename);

	speed = spd;
	area = size;
	radius = rad;
}

Attack::~Attack()
{}

void Attack::setStat(Stat s)
{
	stat = s;
}

void Attack::slash(bool click, string direction, int posx, int posy, SDL_Point cen)
{
	if (atkBox.size() == 0)
	{
		if (click)
		{
			center.x = cen.x + radius.x;
			center.y = cen.y + radius.y + area.y;

			attackDirection(direction);

			xpos = posx;
			ypos = posy;

			box.center = center;

			box.destRect.w = area.x * GameSetting::scaleX;
			box.destRect.h = area.y * GameSetting::scaleY;
			box.destRect.x = xpos - radius.x - Camera::xcam;
			box.destRect.y = ypos - radius.y - area.y - Camera::ycam;

			box.hitRect = hitRect;

			box.checkRect = box.hitRect;
			box.checkRect.x = box.hitRect.x - Camera::xcam;
			box.checkRect.y = box.hitRect.y - Camera::ycam;

			box.angle = angle;

			atkBox.push_back(box);
		}
	}

	if (atkBox.size() != 0)
	{
		aniX += speed;
		aniY = 20;

		if (aniX >= 60)
		{
			aniX = 0;
			atkBox.clear();
			hit(hitRect);
		}
		
	srcRect.w = 20;
	srcRect.h = 20;
	srcRect.x = aniX;
	srcRect.y = aniY;
	}
}

void Attack::pierce(bool click, string direction, int posx, int posy, SDL_Point cen)
{
	if (atkBox.size() == 0)
	{
		if (click)
		{
			center.x = cen.x + radius.x;
			center.y = cen.y + radius.y + area.y;

			attackDirection(direction);

			xpos = posx;
			ypos = posy;

			box.center = center;

			box.destRect.w = area.x * GameSetting::scaleX;
			box.destRect.h = area.y * GameSetting::scaleY;
			box.destRect.x = xpos - radius.x - Camera::xcam;
			box.destRect.y = ypos - radius.y - area.y - Camera::ycam;

			box.hitRect = hitRect;

			box.checkRect = box.hitRect;
			box.checkRect.x = box.hitRect.x - Camera::xcam;
			box.checkRect.y = box.hitRect.y - Camera::ycam;

			box.angle = angle;

			atkBox.push_back(box);
		}
	}

	if (atkBox.size() != 0)
	{
		aniX = 20;
		aniY += speed;

		if (aniY >= 60)
		{
			aniY = 0;
			atkBox.clear();
			hit(hitRect);
		}
	
		srcRect.w = 20;
		srcRect.h = 20;
		srcRect.x = aniX;
		srcRect.y = aniY;
	}
}

void Attack::blunt(bool click, string direction, int posx, int posy, SDL_Point cen)
{
	if (atkBox.size() == 0)
	{
		if (click)
		{
			center.x = cen.x + radius.x;
			center.y = cen.y + radius.y + area.y;

			attackDirection(direction);

			xpos = posx;
			ypos = posy;

			box.center = center;

			box.destRect.w = area.x * GameSetting::scaleX;
			box.destRect.h = area.y * GameSetting::scaleY;
			box.destRect.x = xpos - radius.x - Camera::xcam;
			box.destRect.y = ypos - radius.y - area.y - Camera::ycam;

			box.hitRect = hitRect;

			box.checkRect = box.hitRect;
			box.checkRect.x = box.hitRect.x - Camera::xcam;
			box.checkRect.y = box.hitRect.y - Camera::ycam;

			box.angle = angle;

			atkBox.push_back(box);
		}
	}

	if (atkBox.size() != 0)
	{
		aniX = 20;
		aniY += speed;

		if (aniY >= 60)
		{
			aniY = 0;
			atkBox.clear();
			hit(hitRect);
		}

		srcRect.w = 20;
		srcRect.h = 20;
		srcRect.x = aniX;
		srcRect.y = aniY;
	}
}

void Attack::shoot(bool click, int x, int y, int posx, int posy, SDL_Point cen)
{
	if (true)
	{
		if (click)
		{	
			aniX = 20;
			aniY = 20;

			srcRect.w = 20;
			srcRect.h = 20;
			srcRect.x = aniX;
			srcRect.y = aniY;
			
			xpos = posx;
			ypos = posy;
			
			box.goal.x = x;
			box.goal.y = y;

			center.x = area.x / 2;
			center.y = area.y / 2;

			angle = atan2((x - xpos - cen.x), (ypos + cen.y - y)) * 180 / PI;

			box.angle = angle;

			box.center = center;

			box.xpos = xpos;
			box.ypos = ypos;

			box.destRect.w = area.x * GameSetting::scaleX;
			box.destRect.h = area.y * GameSetting::scaleY;
			box.destRect.x = box.xpos - radius.x - Camera::xcam;
			box.destRect.y = box.ypos + cen.y - (area.y / 2) - Camera::ycam;

			box.hitRect.w = area.x * GameSetting::scaleX;
			box.hitRect.h = area.x * GameSetting::scaleY;
			box.hitRect.x = box.xpos - radius.x;
			box.hitRect.y = box.ypos - radius.x;

			box.move = 0;
			box.xmove = 0;
			box.ymove = 0;

			atkBox.push_back(box);
		}
	}

	for (int i = 0; i < atkBox.size(); i++)
	{
		atkBox[i].move += speed;
		atkBox[i].xmove += speed * sin(angle * PI / 180);
		atkBox[i].ymove += speed * cos(angle * PI / 180);

		atkBox[i].destRect.x = box.xpos - radius.x - Camera::xcam;
		atkBox[i].destRect.y = box.ypos + cen.y - (area.y / 2) - Camera::ycam - atkBox[i].move;

		atkBox[i].hitRect.x = box.xpos - radius.x + atkBox[i].xmove;
		atkBox[i].hitRect.y = box.ypos - radius.x - atkBox[i].ymove;

		atkBox[i].center.y += speed;

		atkBox[i].checkRect = atkBox[i].hitRect;
		atkBox[i].checkRect.x -= Camera::xcam;
		atkBox[i].checkRect.y -= Camera::ycam;

		int xCheck = atkBox[i].xpos - radius.x;
		int yCheck = atkBox[i].ypos + cen.y - (area.y / 2) - atkBox[i].move;


		if (atkBox[i].move >= sqrt(pow(atkBox[i].goal.x - xCheck - atkBox[i].center.x, 2) + pow(yCheck + atkBox[i].center.y - atkBox[i].goal.y, 2)))
		{
			atkBox.erase(atkBox.begin() + i);
		}

		else
		{
			if (hit(atkBox[i].hitRect))
			{
				atkBox.erase(atkBox.begin() + i);
			}
		}
	}
}

void Attack::attackDirection(string direction)
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

bool Attack::hit(SDL_Rect rect)
{
	for (int i = 0; i < ObjectManager::list.size(); i++)
	{
		if (ObjectManager::object[i].renderState)
		{
			objRect.x = ObjectManager::list[i].x;
			objRect.y = ObjectManager::list[i].y;
			objRect.h = ObjectManager::list[i].height;
			objRect.w = ObjectManager::list[i].width;
			if (Collision(rect, objRect))
			{
				cout << "hit" << endl;
				ObjectManager::list[i].HP -= damage();
				if (ObjectManager::list[i].HP <= 0)
				{
					ObjectManager::remove(i);
				}

				return true;
			}
		}
	}

	return false;
}

int Attack::damage()
{
	int damage = stat.STR;

	return damage;
}

void Attack::render()
{
	for (int i = 0; i < atkBox.size(); i++)
	{
		if (TextManager::RenderCheck(atkBox[i].checkRect))
		{
			TextManager::RotateDraw(texture, srcRect, atkBox[i].destRect, atkBox[i].angle, atkBox[i].center);
		}
	}
}