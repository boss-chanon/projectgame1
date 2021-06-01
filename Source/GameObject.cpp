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

	destRect.w = width * GameSetting::scaleX;
	destRect.h = height * GameSetting::scaleY;
	destRect.x = xpos - Camera::xcam;
	destRect.y = ypos - Camera::ycam;

	renderState = TextManager::RenderCheck(destRect);
}

void GameObject::render()
{
	if (renderState)
	{
		SDL_RenderCopy(Game::renderer, texture, &srcRect, &destRect);
	}
}