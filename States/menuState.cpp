#include "menuState.h"

menuState::menuState(engine* gEngine)
{
	init(gEngine);
}

void menuState::init(engine* gEngine)
{
	font = TTF_OpenFont("AmaticSC-Regular.ttf",100);

	if (font == nullptr)
		perror("Cannot open font\n");
	else
		printf("font opened\n");
	
	textSprite* startImage = new textSprite("Start Game", font, menuColour, gEngine->getRenderer());
	button* startButton = new button(startImage, startGame);

	start.addComponent(startButton);

	start.x = gEngine->screenWidth()/2;
	start.y = gEngine->screenHeight()/2;
}

void menuState::handleInput(engine* gEngine,float deltaTime)
{
	while (SDL_PollEvent(gEngine->event()) != 0)
	{		
		if (gEngine->event()->type == SDL_QUIT)
		{		
			gEngine->stopGame();
		}
	}	
}

void menuState::update(engine* gEngine,float deltaTime)
{
	SDL_SetRenderDrawColor(gEngine->getRenderer(),0xFF,0xFF,0xFF,0xFF);
	SDL_RenderClear(gEngine->getRenderer());

	start.update(gEngine,deltaTime);
	
	SDL_RenderPresent(gEngine->getRenderer());
}

void menuState::startGame(engine* gEngine)
{
	printf("going into game\n");
	SDL_SetRenderDrawColor(gEngine->getRenderer(),0x00,0x00,0x00,0x00);
	SDL_RenderClear(gEngine->getRenderer());
	gEngine->changeGameState(inGame);
}

menuState::~menuState()
{
	close();
}

void menuState::close()
{
	
}
