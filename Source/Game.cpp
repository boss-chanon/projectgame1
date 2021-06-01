#include "Game.h"
#include "GameObject.h"
#include "TextManager.h"
#include "Player.h"
#include "Map.h"
#include "ObjectManager.h"
#include "MapManager.h"
#include "TimeManager.h"
#include "Item.h"
#include "PlayerPosition.h"
#include "GameSetting.h"
#include "PlayerData.h"

Player* player1;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

int Game::width;
int Game::height;

string Game::ID;
string Game::password;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int w, int h, bool fullscreen)
{
	GameSetting::load("../JsonFile/GameSetting.json");

	while (!PlayerData::login(ID, password))
	{
		cout << "ID: ";
		cin >> ID;
		cout << "password: ";
		cin >> password;
	}

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
		SDL_GetWindowSize(window, &width, &height);
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		
		GameSetting::setSize(width, height);
		PlayerData::load();
		TimeManager::timeSet();
		Item::loadItem(GameSetting::item);
		MapManager::loadData(GameSetting::map, PlayerData::map);
		StatManager::loadStat(GameSetting::stat);

		player1 = new Player(PlayerData::image, PlayerData::ID);
		PlayerPosition::setPosition(PlayerData::position.x, PlayerData::position.y);

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
	MapManager::map->updateMap();
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

void Game::save()
{
	MapManager::saveData();
	PlayerData::save();
}

void Game::end()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit;
}