#include "Game.h"
#include "GameObject.h"
#include "TextManager.h"
#include "Player.h"

Player player1;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		player1.init("image/test2.png", 0, 0);

		isRunning = true;
	}
}

void Game::handleEvent()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update()
{
	player1.move();
}

void Game::render()
{
	SDL_RenderClear(renderer);

	player1.render();

	SDL_RenderPresent(renderer);
}

void Game::end()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit;
}