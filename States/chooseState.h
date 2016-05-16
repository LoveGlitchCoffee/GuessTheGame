#pragma once

#include "../States/inGameState.h"
#include "../GameEngine/engine.h"
#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "../Components/sprite.h"
#include "../Components/button.h"

class chooseState : public gameState
{
public:
	
	chooseState(engine* gEngine);
	~chooseState();
	
	void init(engine* gEngine);

	void close();

	void handleInput(engine* gEngine, float deltaTime);

	void update(engine* gEngine, float deltaTime);
	
private:

	static void choseFolder1(engine* gEngine);

	static void hoverOver(button* folder);
	
	gameObject folder1;

	bool canUpdate;
	
};
