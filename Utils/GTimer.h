#pragma once

#include <SDL2/SDL.h>

class GTimer
{
public:

	/** 
	 * @brief initialise the start tick to 0 and set the flag that timer started
	 * 
	 */
	GTimer();

	/** 
	 * @brief calls the stop function
	 * 
	 */
	~GTimer();

	/** 
	 * @brief start the timer with the start tick set to the value returned by SDL_GetTicks();
	 * 
	 */
	void start();

	/** 
	 * @brief Stops the clock, basically re-initialise the start tick and set the flag that timer started
	 * 
	 */
	void stop();

	/** 
	 * @brief reset the timer so the start tick is SDL_GetTicks again
	 * 
	 */
	void resetStartTime();

	/** 
	 * @brief return the milliseconds that has passed since the timer start (value of startTick)
	 * 
	 * @return the delta time in milliseconds
	 */
	Uint32 getDelataTicks();

private:
	
	Uint32 startTick;   
	
	bool timerStarted;	
};
