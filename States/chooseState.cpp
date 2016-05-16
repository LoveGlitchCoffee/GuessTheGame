#include "chooseState.h"

chooseState::chooseState(engine* gEngine)
{
	canUpdate = true;
	
	font = TTF_OpenFont("AmaticSC-Regular.ttf",60);

	if (font == nullptr)
		perror("Cannot open font\n");
	else
		printf("font opened\n");
	
	init(gEngine);
}

void chooseState::init(engine* gEngine)
{
	int space;
	// rogues
	sprite* folderSprite  = new sprite("folder-icon.png",gEngine->getRenderer());

    space = folderSprite->height();
	
	button* rogueBut = new button(folderSprite, chosenRogue);
	rogueBut->setHoverCallback(hoverOver);
	
	rogue.addComponent(rogueBut);

    rogue.x = gEngine->screenWidth() / 4;
    rogue.y = gEngine->screenHeight() / 3;

	textSprite* rogueT = new textSprite("Roguelike-lite",font,col,gEngine->getRenderer());
	rogueText.addComponent(rogueT);

	rogueText.x = rogue.x;
	rogueText.y = rogue.y - space;

	// rpgs

	sprite* folderSprite1  = new sprite("folder-icon.png",gEngine->getRenderer());
	
	button* rpgBut = new button(folderSprite1, chosenRPG);
    rpgBut->setHoverCallback(hoverOver);
	
    rpgs.addComponent(rpgBut);

    rpgs.x = gEngine->screenWidth() / 4 * 2;
    rpgs.y = gEngine->screenHeight() / 3;

	textSprite* rpgT = new textSprite("RPGs",font,col,gEngine->getRenderer());
    rpgText.addComponent(rpgT);

    rpgText.x = rpgs.x;
    rpgText.y = rpgs.y - space;
	
	// stealth

	sprite* folderSprite2  = new sprite("folder-icon.png",gEngine->getRenderer());
	
	button* stealthBut = new button(folderSprite2, chosenStealth);
    stealthBut->setHoverCallback(hoverOver);
	
    stealth.addComponent(stealthBut);

    stealth.x = gEngine->screenWidth() / 4 * 3;
    stealth.y = gEngine->screenHeight() / 3;

	textSprite* stealthT = new textSprite("Stealth",font,col,gEngine->getRenderer());
    stealthText.addComponent(stealthT);

    stealthText.x = stealth.x;
    stealthText.y = stealth.y - space;

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

	rogueText.update(gEngine,deltaTime);
    rogue.update(gEngine,deltaTime);

    rpgText.update(gEngine,deltaTime);
    rpgs.update(gEngine,deltaTime);

	stealthText.update(gEngine,deltaTime);
    stealth.update(gEngine,deltaTime);

	SDL_RenderPresent(gEngine->getRenderer());
}

void chooseState::chosenRogue(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("roguelike-lite");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenRPG(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("rpgs");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenStealth(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("stealth");
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
