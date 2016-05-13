#pragma once

#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "../Components/textSprite.h"
#include "../Components/button.h"

class menuState : public gameState
{
public:

	menuState(engine* gEngine);	
	
	void init(engine* gEngine);

	~menuState();

	void close();

	void handleInput(engine* gEngine, float deltaTime);

	void update(engine* gEngine, float deltaTime);

private:

	gameObject start;

	TTF_Font* font;
	SDL_Color menuColour {0,0,0,255};

	static void startGame(engine* gEngine);
};
