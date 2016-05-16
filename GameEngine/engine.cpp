#include "engine.h"
#include "../States/menuState.h"
#include "../States/chooseState.h"
#include "../States/inGameState.h"
#include "../States/endGame.h"

engine::engine()
{
	// define screen size
	SCREEN_WIDTH = 800;
	SCREEN_HEIGHT = 600;
	
	gameRunning = true;
	
	init();
}

engine::~engine()
{
	// current state does not need to free
	currentState = nullptr;

	for (int i = 0; i < states.size(); ++i)
	{
		delete states[i];
	}
	
	close();
}

bool engine::init()
{	
	bool success = true;	
	
	// initialise SDL and IMG
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("fail init");
		success = false;			
	}
	else
	{
		
		gWindow = SDL_CreateWindow("Guess the Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (gWindow == NULL)
		{
			printf("can't create window %s\n",SDL_GetError());
			success = false;
		}
		else
		{
			
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			
			if (gRenderer == NULL)
			{
				printf("can't intialise renderer %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF,0xFF,0xFF,0xFF);
				
				int imgFlags = IMG_INIT_PNG;
				
				if (! (IMG_Init(imgFlags) & imgFlags))
				{
					printf("cannot load pngs");
					success = false;
				}
								 
				if (TTF_Init() == -1)
				{
					printf("cannot use ttf");
					success = false;
				}
			}

			// initialise states
			states.reserve(4);
			
			menuState* menu = new menuState(this);
			states.push_back(menu);

			chooseState* choose = new chooseState(this);
			states.push_back(choose);

			inGameState* inGame = new inGameState(this);
			states.push_back(inGame);

			endGameState* endGame = new endGameState(this);
			states.push_back(endGame);
		}
	}
	
	return success;
}


void engine::close()
{	
	
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);

	gWindow = nullptr;
	gRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

void engine::changeGameState(gState newState)
{	
	currentState = states[newState];
}

void engine::handleInput(float deltaTime)
{
	currentState->handleInput(this, deltaTime);
}

void engine::update(float deltaTime)
{
	currentState->update(this, deltaTime);
}

SDL_Renderer* engine::getRenderer()
{
	return gRenderer;
}

int engine::screenWidth()
{
	return SCREEN_WIDTH;
}

int engine::screenHeight()
{
	return SCREEN_HEIGHT;
}

bool engine::isRunning()
{
	return gameRunning;
}

void engine::stopGame()
{
	gameRunning = false;
}

SDL_Event* engine::event()
{
	return &e;
}

gameState* engine::getState(int index)
{
	return states.at(index);
}
