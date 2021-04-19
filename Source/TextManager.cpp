#include "TextManager.h"

SDL_Texture* TextManager::LoadTexture(const char* filename)
{
	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, surface);

	return tex;
}