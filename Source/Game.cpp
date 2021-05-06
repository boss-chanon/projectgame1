#include "Game.h"
#include "GameObject.h"
#include "TextManager.h"
#include "Player.h"
#include "Map.h"
#include "ObjectManager.h"
#include "MapManager.h"
#include "TimeManager.h"
#include "Item.h"

Player* player1;

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
		
		TimeManager::timeSet();
		Item::loadItem("../JsonFile/itemTest.json");
		MapManager::loadData("../JsonFile/maptest.json", "map0");
		player1 = new Player("../image/test2.png");

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
	MapManager::map->loadMap();
	player1->update();
	ObjectManager::update();
	MapManager::spawnObject(60000);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	MapManager::map->drawMap();
	player1->render();
	ObjectManager::render();

	SDL_RenderPresent(renderer);
}

void Game::end()
{
	MapManager::saveData();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit;
}