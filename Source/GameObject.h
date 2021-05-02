#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Camera.h"
#include "Player.h"
#include "ObjectData.h"

class GameObject
{
public:
	GameObject(ObjectData data);

	void update();
	void render();
private:
	int xpos, ypos;
	int width, height;
	char* filename;
	bool renderState;
	string str;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
};