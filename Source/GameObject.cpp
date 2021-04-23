#include "GameObject.h"

SDL_Rect GameObject::destRect;
SDL_Rect GameObject::srcRect;

GameObject::GameObject(const char* filename, int w, int h, int x, int y)
{
	texture = TextManager::LoadTexture(filename);

	width = w;
	height = h;
	xpos = x;
	ypos = y;

	center.x = width / 2;
	center.y = height / 2;
}

void GameObject::update()
{
	srcRect.w = TextManager::width;
	srcRect.h = TextManager::height;
	srcRect.x = srcRect.y = 0;

	destRect.w = width + 20;
	destRect.h = height + 20;
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
		TextManager::Draw(texture, srcRect, destRect);
	}
}