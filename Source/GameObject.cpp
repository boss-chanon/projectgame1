#include "GameObject.h"

GameObject::GameObject(ObjectData data)
{
	str = data.filename;
	filename = const_cast<char*>(str.c_str());

	texture = TextManager::LoadTexture(filename);

	width = data.width;
	height = data.height;
	xpos = data.x;
	ypos = data.y;
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
}