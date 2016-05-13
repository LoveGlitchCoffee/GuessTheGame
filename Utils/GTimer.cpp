#include "GTimer.h"

GTimer::GTimer()
{
	startTick = 0;
	
	timerStarted = false;
}

GTimer::~GTimer()
{
	stop();
}

void GTimer::start()
{
	timerStarted = true;
	
	startTick = SDL_GetTicks();
}

void GTimer::stop()
{
	timerStarted = false;
	startTick = 0;
}

Uint32 GTimer::getDelataTicks()
{
	Uint32 tickPassed = SDL_GetTicks();
	return tickPassed - startTick;
}

void GTimer::resetStartTime()
{
	startTick = SDL_GetTicks();
}
