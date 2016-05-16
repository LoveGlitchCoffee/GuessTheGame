#include "inGameState.h"

inGameState::inGameState(engine* gEngine)
{		
	notClearScreen = true;
}

void inGameState::setPath(string path)
{
	filePath = path;
}

void inGameState::init(engine* gEngine)	
{
	resetAll();
		
	getImages();   

	int tilesX = 4;
	int tilesY = 3;
	int tileSize = 200;

	bool posAssigned = false;

	for (int i = 0; i < imageCounter; ++i)
	{
		gameObject* newObj = new gameObject();
		sprite* newImage = new sprite(filePath + imageFiles[i],gEngine->getRenderer());
		newObj->addComponent(newImage);
		
		imageObj[i] = newObj;
		
		for (int x = 0; x < tilesX; ++x)
		{
			for (int y = 0; y < tilesY; ++y)
			{				
				newImage->addClip(x * tileSize, y * tileSize, tileSize, tileSize);
				
				if (!posAssigned)
				{
					clipPosition.push_back(pair<int,int>(x * tileSize + tileSize/2,y * tileSize + tileSize/2));
				}
			}
		}

		if (!posAssigned)
			posAssigned = true;
		
		imageObj[i]->x = gEngine->screenWidth() / 2;
		imageObj[i]->y = gEngine->screenHeight() / 2;
	}

	for (int i = 0; i < 12; ++i)
	{
		randomSequence.push_back(i);
	}

	std::random_shuffle(randomSequence.begin(),randomSequence.end());
}

void inGameState::resetAll()
{
	imageCounter = 0;
	currentImage = 0;

	clearCounter = 0;
    currentTime = 0; // 3 seconds for each piece

	pointLeft = 12;
	totalPoints = 0;

	randomSequence.clear();
	clipPosition.clear();

	for (int i = 0; i < imageCounter; ++i)
	{
		delete imageObj[i];
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

		if (closedir(dir) < 0)
			perror("failed closing directory\n");
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
		else if (gEngine->event()->type == SDL_KEYDOWN)
		{
			switch(gEngine->event()->key.keysym.sym)
			{
			case SDLK_SPACE:
			{
				totalPoints += pointLeft;
				pointLeft = 12;
				// also reset clip
				clearCounter = 0;
				currentTime = 0;

				SDL_SetRenderDrawColor(gEngine->getRenderer(),0x00,0x00,0x00,0x00);
				SDL_RenderClear(gEngine->getRenderer());
			   	   
				++currentImage;
				printf("current image %d\n", currentImage);
			}
			break;

			case SDLK_x:
			{
				clearCounter = 0;
				currentTime = 0;
		
				SDL_SetRenderDrawColor(gEngine->getRenderer(),0x00,0x00,0x00,0x00);
				SDL_RenderClear(gEngine->getRenderer());
		
				if (currentImage == imageCounter + 1)
				{
					// for 1up, score at the end of all teams, adapt as needed
					printf("final score: %d\n",totalPoints);					
					gEngine->changeGameState(endGame);
				}
				else
				{
					printf("image %d skipped\n",currentImage);
					++currentImage;
				}
			}
			break;
			}
		}
	}
}


void inGameState::update(engine* gEngine, float deltaTime)
{
	if (notClearScreen)
	{
		SDL_SetRenderDrawColor(gEngine->getRenderer(),0x00,0x00,0x00,0x00);
		SDL_RenderClear(gEngine->getRenderer());
		notClearScreen = false;
	}
	
	if (currentImage == imageCounter)
	{
		printf("final score: %d\n",totalPoints);
		gEngine->changeGameState(endGame);
	}
	else
	{
		
		if (clearCounter == clearTime)
		{
			printf("failed this one\n");
			pointLeft = 12;
			
			clearCounter = 0;
			currentTime = 0;
		
			SDL_SetRenderDrawColor(gEngine->getRenderer(),0x00,0x00,0x00,0x00);
			SDL_RenderClear(gEngine->getRenderer());
			
			++currentImage;
			printf("image auto update to %d\n",currentImage);
		}
		else if (timeToReveal(deltaTime) && clearCounter < clearTime)
		{
			moveImage(imageObj[currentImage]);
			imageObj[currentImage]->update(gEngine,deltaTime);
			++clearCounter;			
			--pointLeft;		
		}
	}
	   		
	SDL_RenderPresent(gEngine->getRenderer());
}

bool inGameState::timeToReveal(float deltaTime)
{
	currentTime += deltaTime;

	if (currentTime >= revealTime)
	{
		currentTime = 0;
		return true;
	}

	return false;
}

void inGameState::moveImage(gameObject* image)
{
	int index = randomSequence.at(clearCounter);
	
	pair<int,int> pos = clipPosition.at(index);

	image->x = pos.readValue1();
	image->y = pos.readValue2();

	sprite* sp = (sprite*) image->getComponent(0);
	sp->setClip(index);
}

inGameState::~inGameState()
{
	for (int i = 0; i < 10; ++i)
	{
		delete imageObj[i];
	}

	close();
}

void inGameState::close()
{
	
}
