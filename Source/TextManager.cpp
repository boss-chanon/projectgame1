#include "TextManager.h"

int TextManager::height;
int TextManager::width;

SDL_Texture* TextManager::LoadTexture(const char* filename)
{
	SDL_Surface* surface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);

	height = surface->h;
	width = surface->w;

	return tex;
}

void TextManager::Draw(SDL_Texture* Tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, Tex, &src, &dest);
}

void TextManager::RotateDraw(SDL_Texture* Tex, const SDL_Rect src, const SDL_Rect dest, double angle, SDL_Point center)
{
	SDL_RenderCopyEx(Game::renderer, Tex, &src, &dest, angle, &center, SDL_FLIP_NONE);
}

bool TextManager::RenderCheck(SDL_Rect rect)
{
	if (((rect.x + rect.w) < 0) || (rect.x > Game::width) || ((rect.y + rect.h) < 0) || (rect.y > Game::height))
	{
		return false;
	}
	return true;
}
