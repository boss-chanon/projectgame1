#include "Player.h"
#include "TextManager.h"
#include <iostream>

SDL_Point Player::position;
int Player::speed;

Player::Player(const char* filename)
{
	texture = TextManager::LoadTexture(filename);

	area.x = 80;
	area.y = 16;
	
	radius.x = (area.x - 64) / 2;
	radius.y = 10;

	attack = new Attack("image/testATK.png", area, 5, radius);
}

void Player::update()
{
	move(3);
	attack->shoot(direction, destRect.x, destRect.y, center);
}

void Player::move(int s)
{
	speed = s;

	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			position.x = 0;
			position.y = -1;
			aniPos = 0;
			walk();
			direction = "Top";
			break;
		case SDLK_a:
			position.x = -1;
			position.y = 0;
			aniPos = 1;
			walk();
			direction = "Left";
			break;
		case SDLK_s:
			position.x = 0;
			position.y = +1;
			aniPos = 2;
			walk();
			direction = "Buttom";
			break;
		case SDLK_d:
			position.x = +1;
			position.y = 0;
			aniPos = 3;
			walk();
			direction = "Right";
			break;
		default:
			break;
		}
	}

	if (Game::event.type == SDL_KEYUP)
	{
		aniWalk = walkCount = 0;
		position.x = 0;
		position.y = 0;
	}

	center.x = destRect.w / 2;
	center.y = destRect.h / 2;

	srcRect.w = 32;
	srcRect.h = 32;
	srcRect.x = aniWalk * srcRect.w;
	srcRect.y = aniPos * srcRect.h;

	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
	destRect.x = Camera::center().x - center.x;
	destRect.y = Camera::center().y - center.y;
}

void Player::walk()
{
	walkCount++;
	if (walkCount == 8)
	{
		walkCount = 0;
		aniWalk++;
	}
	if (aniWalk > 3)
	{
		aniWalk = 0;
	}
}

void Player::render()
{
	attack->render();
	TextManager::Draw(texture, srcRect, destRect);
}