#include "Player.h"
#include "TextManager.h"
#include "StatManager.h"
#include <iostream>

Player::Player(string filename, string ID)
{
	texture = TextManager::LoadTexture(const_cast<char*>(filename.c_str()));

	fileHeight = TextManager::height;
	fileWidth = TextManager::width;

	name = ID;

	stat = StatManager::getStat(name);
	inventory = new Inventory(GameSetting::inventory, name, 64);
	inventory->load();
	equipment = new Equipment(inventory, GameSetting::equipment, name);
}

void Player::update()
{
	int x, y;
	bool click = false;

	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		x += Camera::xcam;
		y += Camera::ycam;
		click = true;
	}

	move();
	PlayerPosition::sizeSet(destRect.w, destRect.h);
	PlayerPosition::move(position, speed);
	equipment->setStat(stat);
	equipment->attack(click, x, y, direction, PlayerPosition::rect.x, PlayerPosition::rect.y, center);
	StatManager::saveStat(name, stat);
}

void Player::move()
{
	speed = 3;
	int frame = 4;

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
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			position.y = 0;
			aniWalk = walkCount = 0;
			break;
		case SDLK_a:
			position.x = 0;
			aniWalk = walkCount = 0;
			break;
		case SDLK_s:
			position.y = 0;
			aniWalk = walkCount = 0;
			break;
		case SDLK_d:
			position.x = 0;
			aniWalk = walkCount = 0;
			break;
		default:
			break;
		}
	}

	center.x = destRect.w / 2;
	center.y = destRect.h / 2;

	srcRect.w = fileWidth / frame;
	srcRect.h = fileHeight / frame;
	srcRect.x = aniWalk * srcRect.w;
	srcRect.y = aniPos * srcRect.h;

	destRect.w = GameSetting::charactorSize().x;
	destRect.h = GameSetting::charactorSize().y;
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
	equipment->render();
	TextManager::Draw(texture, srcRect, destRect);
}