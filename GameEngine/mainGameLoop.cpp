#include "../Utils/GTimer.h"

#include "engine.h"

GTimer timer;

const Uint32 FRAME_RATE = 60;
Uint32 deltaTime;

/**
 * @brief determines if its been 1 frame/tick
 */
bool timeToUpdate()
{
	bool timeToUpdate = false;

	deltaTime = timer.getDelataTicks();   	
	
	if (deltaTime >= (1000 / FRAME_RATE))
	{
		timeToUpdate = true;
	}

	return timeToUpdate;	   	
}

/**
 * @brief The main game loop
 */
int main(int argc, char *argv[])
{
	engine gameEngine;

	gameEngine.changeGameState(menu);		
	
	while (gameEngine.isRunning())
	{
		if (timeToUpdate())
		{
			gameEngine.handleInput(deltaTime/1000.0);
			gameEngine.update(deltaTime/1000.0);
			timer.resetStartTime();
		}		
	}
	
	// don't have to do cleanup because in destructor of engine
	
	return 0;
}

