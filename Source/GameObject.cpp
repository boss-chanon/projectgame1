#include "GameObject.h"

GameObject::GameObject(const char* filename, int x, int y)
{
	texture = TextManager::LoadTexture(filename);
	
}

void GameObject::update()
{

}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, texture, &srcRect, &dectRect);
}