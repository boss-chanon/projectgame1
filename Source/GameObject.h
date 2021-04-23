#pragma once

#include "Game.h"
#include "TextManager.h"
#include "Camera.h"
#include "Player.h"

class GameObject
{
public:
	GameObject(const char* filename, int width, int height, int x, int y);
	~GameObject();

	void update();
	static bool Collision(const SDL_Rect rec);
	void render();

private:
	int xpos, ypos;
	int width, height;
	bool renderState;
	
	SDL_Point center;
	SDL_Texture* texture;
	static SDL_Rect srcRect, destRect;
};