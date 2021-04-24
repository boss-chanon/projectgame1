#include "GameObject.h"

GameObject::GameObject(const char* filename, int w, int h, int x, int y)
{
	texture = TextManager::LoadTexture(filename);

	width = w;
	height = h;
	xpos = x;
	ypos = y;
}

void GameObject::update()
{
	srcRect.w = 32;
	srcRect.h = 32;
	srcRect.x = srcRect.y = 0;

	destRect.w = width;
	destRect.h = height;
	destRect.x = xpos - Camera::xmove();
	destRect.y = ypos - Camera::ymove();

	if (((destRect.x + width) < 0) || (destRect.x > Game::width) || ((destRect.y + height) < 0) || (destRect.y > Game::height))
	{
		renderState = false;
	}

	else
	{
		renderState = true;
	}

}

void GameObject::render()
{
	if (renderState)
	{
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
	}

	SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);

}