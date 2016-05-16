#include "endGame.h"

endGameState::endGameState(engine* gEngine)
{
	init(gEngine);
}

void endGameState::init(engine* gEngine)
{
	endFont = TTF_OpenFont("AmaticSC-Regular.ttf",100);
	
	textSprite* finSprite = new textSprite("Thats all folks", endFont,endColour,gEngine->getRenderer());
	
	textSprite* resSprite = new textSprite("Restart?",endFont,endColour,gEngine->getRenderer());

	button* resButton = new button(resSprite,restart);

	finText.addComponent(finSprite);
	finText.x = gEngine->screenWidth() / 2;
	finText.y = gEngine->screenHeight() / 3;

	resText.addComponent(resButton);
	resText.x = gEngine->screenWidth() / 2;
	resText.y = gEngine->screenWidth() / 3 * 2;
}

void endGameState::restart(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);
	inG->notClearScreen = true;
	gEngine->changeGameState(chooseFolder);
}

void endGameState::handleInput(engine* gEngine, float deltaTime)
{
	while (SDL_PollEvent(gEngine->event()) != 0)
	{		
		if (gEngine->event()->type == SDL_QUIT)
		{
			close();
			gEngine->stopGame();
		}
	}
}

void endGameState::update(engine* gEngine, float deltaTime)
{
	SDL_SetRenderDrawColor(gEngine->getRenderer(),0xFF,0xFF,0xFF,0xFF);
	SDL_RenderClear(gEngine->getRenderer());
	
	finText.update(gEngine,deltaTime);
	resText.update(gEngine,deltaTime);

	SDL_RenderPresent(gEngine->getRenderer());
}

endGameState::~endGameState()
{
	close();
}

void endGameState::close()
{
	TTF_CloseFont(endFont);
}
