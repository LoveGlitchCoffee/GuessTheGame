#include "inGameState.h"

inGameState::inGameState(engine* gEngine)
{
	imageCounter = 0;
	currentImage = 0;

	clearCounter = 0;
    currentTime = 0; // 3 seconds for each piece
	init(gEngine);
}

void inGameState::init(engine* gEngine)	
{
	getImages();
	string file = "images/";

	int tilesX = 4;
	int tilesY = 3;
	int tileSize = 200;

	bool posAssigned = false;
	
	for (int i = 0; i < imageCounter; ++i)
	{
		sprite* newImage = new sprite(file + imageFiles[i],gEngine->getRenderer());
		imageObj[i].addComponent(newImage);

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
		
		imageObj[i].x = gEngine->screenWidth() / 2;
		imageObj[i].y = gEngine->screenHeight() / 2;
	}

	for (int i = 0; i < 11; ++i)
	{
		randomSequence.push_back(i);
	}

	std::random_shuffle(randomSequence.begin(),randomSequence.end());
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
	if (clearCounter == clearTime)
	{
		// suspend for couple mins
		clearCounter = 0;
		
		SDL_SetRenderDrawColor(gEngine->getRenderer(),0x00,0x00,0x00,0x00);
		SDL_RenderClear(gEngine->getRenderer());
		
		if (currentImage == 9)
		{
			// swap scene
		}
		else
		{
			++currentImage;
		}
		
	}
	else if (timeToReveal(deltaTime))
	{
		moveImage(&imageObj[currentImage]);
		imageObj[currentImage].update(gEngine,deltaTime);
		++clearCounter;
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
	
}

void inGameState::close()
{
	
}
