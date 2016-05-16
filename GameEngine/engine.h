#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <vector>

#include "gameState.h"

using std::vector;

class engine
{
public:
	
	/** 
	 * @brief Initialise values like screen height and width.
	 *        Also calls the init() function.
	 */
	engine();
	
	/** 
	 * @brief Free resources used by the engine such as the states.
	 *        Also calls the close() function.
	 */
	~engine();
	
    /** 
	 * Initialises SDL system and subsystems
	 * 
	 * @return whether initialisation has been successful
	 */
	bool init();

	/** 
	 * @brief Closes SDL system and subsystems. Also free-ing any SDL components
	 * 
	 */
	void close();

   /** 
     * @brief Changes the game's current states, does not make any changes to previous state. 
     * 
     * @param newState The new state to change to
     */    
 	void changeGameState(gState newState);

    /** 
	 * @brief Calls the input handling function of the current state
	 * 
	 * @param deltaTime The time has passed since the last call to handleInput in seconds
	 */
	void handleInput(float deltaTime);

    /** 
	 * @brief Calls the update function of the current state
	 * 
	 * @param deltaTime The time has passed since the last call to handleInput in seconds
	 */
	void update(float deltaTime);

	
	/** 
	 * Returns a pointer to the renderer of the game.
	 * 
	 * @return A pointer to the renderer of the game
	 */   
	SDL_Renderer* getRenderer();

    /** 
	 * @brief Returns a pointer to the SDL_Event that was polled
	 * 
	 * @return A pointer to the SDL_Event
	 */
	SDL_Event* event();

	/** 
	 * @brief Returns the screen width
	 * 
	 * @return the screen width
	 */
	int screenWidth();

	/** 
	 * @brief Returns the screen height
	 * 
	 * @return the screen height
	 */
	int screenHeight();

	/** 
	 * @brief Returns whether or not the game is running, i.e. the update functions are called
	 * 
	 * @return Whether the game is running
	 */
	bool isRunning();

	/** 
	 * @brief Sets the game's running state to false
	 * 
	 */
	void stopGame();

	gameState* getState(int index);	
	
private:

	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;

	int SCREEN_WIDTH, SCREEN_HEIGHT;

	/// States
	vector<gameState*> states;

	gameState* currentState;
		
	bool gameRunning;
	SDL_Event e;
};
