#include "GameObject.h"

GameObject::GameObject(ObjectData data)
{
	string filename = data.image;

	texture = TextManager::LoadTexture(const_cast<char*>(filename.c_str()));

	width = data.width;
	height = data.height;
	xpos = data.x;
	ypos = data.y;

	fileHeight = TextManager::height;
	fileWidth = TextManager::width;
}

void GameObject::update()
{
	srcRect.w = fileWidth;
	srcRect.h = fileHeight;
	srcRect.x = srcRect.y = 0;

	destRect.w = width;
	destRect.h = height;
	destRect.x = xpos - Camera::xmove;
	destRect.y = ypos - Camera::ymove;

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
}