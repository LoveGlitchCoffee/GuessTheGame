#include "chooseState.h"

chooseState::chooseState(engine* gEngine)
{
	canUpdate = true;
	
	font = TTF_OpenFont("AmaticSC-Regular.ttf",40);

	if (font == nullptr)
		perror("Cannot open font\n");
	else
		printf("font opened\n");
	
	init(gEngine);
}

void chooseState::createMenuItem(string iconPath, string label, void(*callback)(engine* gEngine), int x, int y)
{
    sprite* folderSprite  = new sprite(iconFolder + iconPath + ".png", engineRef->getRenderer());

    int space = folderSprite->height();
	
	button* iconButton = new button(folderSprite, callback);
    iconButton->setHoverCallback(hoverOver);	
	gameObject* buttonObject = new gameObject();    
    buttonObject->addComponent(iconButton);        
    buttonObject->x = engineRef->screenWidth() / 5 * x;
    buttonObject->y = engineRef->screenHeight() / 4 * y;

	textSprite* labelSprite = new textSprite(label, font, col, engineRef->getRenderer());
    
    gameObject* labelObject = new gameObject();
    labelObject->addComponent(labelSprite);
    labelObject->x = buttonObject->x;
    labelObject->y = buttonObject->y - space;

    buttonTable.emplace(label, buttonObject);
    labelTable.emplace(label, labelObject);
}

void chooseState::init(engine* gEngine)
{    
	iconFolder = "images/icons/";
    engineRef = gEngine;

    int maxX = 4;
    int maxY = 3;

    // all the following arrays must be corresponding in order, only ever need to update hese lists
    std::string iconPaths[] = {"roguelike",
                               "rpg-icon",
                               "stealth-icon",
                               "platformer",
                               "fighting-icon",
                               "arpgs",
                               "strategy",
                               "race-icon",
                               "simulator-icon",
                               "puzzle-icon",
                               "open-world-icon",
                               "example-icon"};
    
    labels[0] = "Roguelike-lite";
    labels[1] = "RPGs";
    labels[2] = "Stealth";
    labels[3] = "Platformer";
    labels[4] = "Fighting";
    labels[5] = "ARPGs";
    labels[6] = "Strategy";
    labels[7] = "Racing";
    labels[8] = "Simulator";
    labels[9] = "Puzzle";
    labels[10] = "'Open World'";
    labels[11] = "Example";

    typedef void (*array_of_callbacks)(engine*);
    array_of_callbacks buttonCallbacks[] = {chosenRogue,
                                            chosenRPG,
                                            chosenStealth,
                                            chosenPlatformer,
                                            chosenFighting,
                                            chosenARPG,
                                            chosenStrategy,
                                            chosenRacing,
                                            chosenSimulator,
                                            chosenPuzzle,
                                            chosenOpenWorld,
                                            chosenExample};

    int categoryCounter = 0;
    
    for (int y = 1; y <= maxY; y++)
    {
        for (int x = 1; x <= maxX; x++)
        {
            createMenuItem(iconPaths[categoryCounter], labels[categoryCounter], buttonCallbacks[categoryCounter], x, y);
            categoryCounter++;
        }
    }
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

    for (int i = 0; i < labelTable.size(); i++)
    {
        buttonTable.at(labels[i])->update(gEngine, deltaTime);
        labelTable.at(labels[i])->update(gEngine, deltaTime);
    }
    	
	SDL_RenderPresent(gEngine->getRenderer());
}

void chooseState::coreCallback(engine* gEngine, std::string ingamePath)
{
    inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath(ingamePath);
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

// callbacks are just wrapper around the core-callback function, passing path to it
//@TODO: refacor these
void chooseState::chosenRogue(engine* gEngine)
{
    coreCallback(gEngine, "roguelike-lite");
}

void chooseState::chosenExample(engine* gEngine)
{
    coreCallback(gEngine, "example");
}

void chooseState::chosenPuzzle(engine* gEngine)
{
    coreCallback(gEngine, "puzzle");
}

void chooseState::chosenSimulator(engine* gEngine)
{
    coreCallback(gEngine, "simulator");
}

void chooseState::chosenRacing(engine* gEngine)
{
    coreCallback(gEngine, "racing");
}

void chooseState::chosenFighting(engine* gEngine)
{
    coreCallback(gEngine, "fighting");
}

void chooseState::chosenRPG(engine* gEngine)
{
    coreCallback(gEngine, "rpgs");
}

void chooseState::chosenStealth(engine* gEngine)
{
    coreCallback(gEngine, "stealth");
}

void chooseState::chosenPlatformer(engine* gEngine)
{
    coreCallback(gEngine, "platformer");
}

void chooseState::chosenARPG(engine* gEngine)
{
    coreCallback(gEngine, "arpgs");
}

void chooseState::chosenStrategy(engine* gEngine)
{
    coreCallback(gEngine, "strategy");
}

void chooseState::chosenOpenWorld(engine* gEngine)
{
    coreCallback(gEngine, "openworld");
}

void chooseState::hoverOver(button* folder)
{
	// change for bigger sprite
}

chooseState::~chooseState()
{
	close();
}

void chooseState::close()
{
	TTF_CloseFont(font);
}
