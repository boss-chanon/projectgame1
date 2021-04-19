#pragma once

#include "Game.h"
#include "SDL2/SDL_image.h"

class TextManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename);
};