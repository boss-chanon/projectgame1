#include "Game.h"
#include "GameObject.h"
#include "TextManager.h"
#include "Player.h"
#include "Map.h"
#include "ObjectManager.h"

Player* player1;
Map* mapTest;

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
		
		ObjectManager::objectLoad("../JsonFile/objtest.json");

		player1 = new Player("../image/test2.png");
		mapTest = new Map("../image/maptest1.png");

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
	mapTest->loadMap();
	player1->update();
	ObjectManager::update();
}

void Game::render()
{
	SDL_RenderClear(renderer);

	mapTest->drawMap();
	player1->render();
	ObjectManager::render();

	SDL_RenderPresent(renderer);
}

void Game::end()
{
	ObjectManager::save("../JsonFile/objtest.json");
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit;
}