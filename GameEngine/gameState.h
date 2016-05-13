#pragma once

enum gState
{
	menu = 0,
	inGame = 1,
	endGame = 2
};

class engine;

class gameState
{
public:

	// must be pure, else need definition cuz derived class will call it
	// pure didn't work, defined empty
	// pure didn't work because derived didn't implement ~gameState, they define their own
	virtual ~gameState();
	
	 /** 
	  * Every state will initialises its own variables
	  * 
	  * @param gEngine the game engine
	  */
	virtual void init(engine *gEngine) = 0;


	 /** 
	  * Every state will free any resources it is using
	  * 
	  */
	virtual void close() = 0;

	/** 
	 * Every state will have its own input handling
	 * 
	 */
	virtual void handleInput(engine*,float) = 0;

	/** 
	 *  Every state will update the logic of that state, 
	 *  including drawing to the screen amongst other.
	 */
	virtual void update(engine*, float) = 0;

protected:
	/** 
	 * The state is in charge of calling the engine to change to a different state
	 * 
	 * @param state 
	 * @param gEngine 
	 */
	virtual void changeState(gState state, engine* gEngine);
};
