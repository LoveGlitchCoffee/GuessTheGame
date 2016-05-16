#include "chooseState.h"

chooseState::chooseState(engine* gEngine)
{
	canUpdate = true;
	init(gEngine);
}

void chooseState::init(engine* gEngine)
{
	sprite* folderSprite  = new sprite("folder-icon.png",gEngine->getRenderer());
	button* folderBut = new button(folderSprite,choseFolder1);
	folderBut->setHoverCallback(hoverOver);	
	
	folder1.addComponent(folderBut);

	folder1.x = gEngine->screenWidth() / 4;
	folder1.y = gEngine->screenHeight() / 3;
}

void chooseState::handleInput(engine* gEngine, float deltaTime)
{
	while (SDL_PollEvent(gEngine->event()) != 0)
	{		
		if (gEngine->event()->type == SDL_QUIT)
		{		
			gEngine->stopGame();
		}
	}	
}

void chooseState::update(engine* gEngine, float deltaTime)
{
	SDL_SetRenderDrawColor(gEngine->getRenderer(),0xFF,0xFF,0xFF,0xFF);
	SDL_RenderClear(gEngine->getRenderer());
	
	folder1.update(gEngine,deltaTime);				

	SDL_RenderPresent(gEngine->getRenderer());
}

void chooseState::choseFolder1(engine* gEngine)
{    
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("images/");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::hoverOver(button* folder)
{
	// change for bigger sprite
}

chooseState::~chooseState()
{
	
}

void chooseState::close()
{
	
}
