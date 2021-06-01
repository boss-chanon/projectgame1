#pragma once

#include <SDL2/SDL.h>

class TimeManager
{
public:
	static void timeSet();
	static Uint32 getTime();
	static bool spawnDelay(const int time);
private:
	static Uint32 startTime, delayTime;
};