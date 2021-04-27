#pragma once

#include "Game.h"
#include "SDL2/SDL_image.h"


using namespace std;

class TextManager
{
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* Tex, SDL_Rect src, SDL_Rect dest);
	static void RotateDraw(SDL_Texture* Tex, const SDL_Rect src, const SDL_Rect dest, double angle, SDL_Point center);

	static int width, height;
};