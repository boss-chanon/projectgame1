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
	TextManager::Draw(texture, srcRect, destRect);
}