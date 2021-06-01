#pragma once

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	bool running() { return isRunning; };
	void handleEvent();
	void update();
	void render();
	void save();

	void end();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	static int width, height;
	static string ID, password;
private:
	bool isRunning = false;	
	SDL_Window* window;		
};