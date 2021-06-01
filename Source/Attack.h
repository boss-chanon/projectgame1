#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Collision.h"
#include "Stat.h"
#include "AttackBox.h"
#include "GameSetting.h"
#include <vector>
#include <math.h>

#ifndef PI
#define PI 3.14159265
#endif // PI

class Attack
{
public:
	Attack(const char* filename, SDL_Point size, int spd, SDL_Point rad);
	~Attack();

	void setStat(Stat stat);

	void slash(bool click, string direction, int xpos, int ypos, SDL_Point cen);
	void pierce(bool click, string direction, int xpos, int ypos, SDL_Point cen);
	void blunt(bool click, string direction, int xpos, int ypos, SDL_Point cen);
	void shoot(bool click, int x, int y, int xpos, int ypos, SDL_Point cen);
	
	bool hit(SDL_Rect rect);
	int damage();
	void attackDirection(std::string direction);

	void render();
private:
	int speed, aniX, aniY, xpos, ypos;
	double angle;

	Stat stat;
	vector<AttackBox> atkBox;
	AttackBox box;

	SDL_Rect srcRect, objRect, hitRect;
	SDL_Point area, radius, center;
	SDL_Texture* texture;
};