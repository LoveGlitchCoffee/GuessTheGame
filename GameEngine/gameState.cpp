#include "gameState.h"
#include "engine.h"

gameState::~gameState()
{
	
}

void gameState::changeState(gState state, engine* gEngine)
{
	gEngine->changeGameState(state);
}
