#pragma once

#include "../States/inGameState.h"
#include "../GameEngine/engine.h"
#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "../Components/sprite.h"
#include "../Components/button.h"
#include "../Components/textSprite.h"

class chooseState : public gameState
{
public:
	
	chooseState(engine* gEngine);
	~chooseState();
	
	void init(engine* gEngine);

	void close();

	void handleInput(engine* gEngine, float deltaTime);

	void update(engine* gEngine, float deltaTime);

	string getFolderName();
	
private:
   
	static void hoverOver(button* folder);


	TTF_Font* font;
	SDL_Color col = {0,0,0,255};

	gameObject rogueText;
	gameObject rogue;
	static void chosenRogue(engine* gEngine);

	gameObject rpgText;
	gameObject rpgs;
	static void chosenRPG(engine* gEngine);

	gameObject stealthText;
	gameObject stealth;
	static void chosenStealth(engine* gEngine);

	bool canUpdate;
	
};
