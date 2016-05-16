#pragma once

#include "../GameEngine/engine.h"
#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "chooseState.h"
#include "../Components/textSprite.h"
#include "../Components/button.h"

class endGameState : public gameState
{
public:

	endGameState(engine* gEngine);
	~endGameState();
	
	void init(engine* gEngine);

	void close();

	void handleInput(engine* gEngine, float deltaTime);

	void update(engine* gEngine, float deltaTime);

private:

	static void restart(engine* gEngine);		
	
	TTF_Font* endFont;
	SDL_Color endColour {0,0,0,255};
	gameObject finText;
	gameObject resText;
};
