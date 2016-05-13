#include <cstdio>
#include "inGameState.h"

inGameState::inGameState(engine* gEngine)
{
	imageCounter = 0;
	init(gEngine);
}

void inGameState::init(engine* gEngine)	
{
	getImages();
	string file = "images/";
	for (int i = 0; i < imageCounter; ++i)
	{
		sprite* newImage = new sprite(file + imageFiles[i],gEngine->getRenderer());
		imageObj[i].addComponent(newImage);
		imageObj[i].x = gEngine->screenWidth() / 2;
		imageObj[i].y = gEngine->screenHeight() / 2;
	}
}

void inGameState::getImages()
{   	
	if ((dir = opendir("./images/")) != nullptr)
	{
		while ((ent = readdir(dir)) != nullptr)
		{
			if (ent->d_type == DT_REG)
			{
				imageFiles[imageCounter] = ent->d_name;
				printf("name of file %s\n",imageFiles[imageCounter].c_str());
				++imageCounter;
			}			   
				
		}

		printf("got %d images\n",imageCounter);
	}
	else
	{
		perror("fail to open directory\n");
	}
}

void inGameState::handleInput(engine* gEngine, float deltaTime)
{
	while (SDL_PollEvent(gEngine->event()) != 0)
	{		
		if (gEngine->event()->type == SDL_QUIT)
		{		
			gEngine->stopGame();
		}
	}	
}

void inGameState::update(engine* gEngine, float deltaTime)
{
	SDL_SetRenderDrawColor(gEngine->getRenderer(),0xFF,0xFF,0xFF,0xFF);
	SDL_RenderClear(gEngine->getRenderer());
	
	for (int i = 0; i < imageCounter; ++i)
	{
		imageObj[i].update(gEngine,deltaTime);
	}

	SDL_RenderPresent(gEngine->getRenderer());
}

inGameState::~inGameState()
{
	
}

void inGameState::close()
{
	
}
