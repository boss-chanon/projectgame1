#include "Player.h"
#include "TextManager.h"
#include <iostream>

void Player::init(const char* filename, int x, int y)
{
	texture = TextManager::LoadTexture(filename);

	xpos = x;
	ypos = y;
}

void Player::move()
{
	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			positionY = -1;
			aniPos = 0;
			walk();
			break;
		case SDLK_a:
			positionX = -1;
			aniPos = 1;
			walk();
			break;
		case SDLK_s:
			positionY = +1;
			aniPos = 2;
			walk();
			break;
		case SDLK_d:
			positionX = +1;
			aniPos = 3;
			walk();
			break;
		default:
			break;
		}
	}

	if (Game::event.type == SDL_KEYUP)
	{
		aniWalk = walkCount = 0;
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_w:
			positionY = 0;
			break;
		case SDLK_a:
			positionX = 0;
			break;
		case SDLK_s:
			positionY = 0;
			break;
		case SDLK_d:
			positionX = 0;
			break;
		default:
			break;
		}
	}

	xpos += (positionX * speed);
	ypos += (positionY * speed);

	srcRect.w = 32;
	srcRect.h = 32;
	srcRect.x = aniWalk * 32;
	srcRect.y = aniPos * 32;

	dectRect.w = srcRect.w * 2;
	dectRect.h = srcRect.h * 2;
	dectRect.x = xpos;
	dectRect.y = ypos;

}

void Player::render()
{
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &dectRect);
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