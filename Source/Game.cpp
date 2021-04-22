#include "Game.h"
#include "GameObject.h"
#include "TextManager.h"
#include "Player.h"
#include "Map.h"

Player* player1;
Map* map;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

int Game::width;
int Game::height;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int w, int h, bool fullscreen)
{
	width = w;
	height = h;

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

		player1 = new Player("image/test2.png");
		map = new Map("image/maptest1.png", width, height);

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
	map->loadMap();
	player1->move(3);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->drawMap();
	player1->render();

	SDL_RenderPresent(renderer);
}

void Game::end()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit;
}