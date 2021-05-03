#include "TimeManager.h"

Uint32 TimeManager::startTime, TimeManager::delayTime;

void TimeManager::timeSet()
{
	startTime = SDL_GetTicks();
	delayTime = SDL_GetTicks();
}

Uint32 TimeManager::getTime()
{
	Uint32 time = SDL_GetTicks() - startTime;

	return time;
}

bool TimeManager::delay(const int time)
{
	if (time <= SDL_GetTicks() - delayTime)
	{
		delayTime = SDL_GetTicks();

		return true;
	}

	return false;
}