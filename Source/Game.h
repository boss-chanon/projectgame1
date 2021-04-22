#pragma once

#include <SDL2/SDL.h>
#include <iostream>

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

	void end();

	static SDL_Renderer* renderer;
	static SDL_Event event;

	static int width, height;
private:
	bool isRunning = false;	
	SDL_Window* window;		
};