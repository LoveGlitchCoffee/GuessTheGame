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

void chooseState::createMenuItem(string iconPath, string label)
{
    
}

void chooseState::init(engine* gEngine)
{
	int space;
	iconFolder = "images/icons/";
	
	// rogues
	sprite* folderSprite  = new sprite(iconFolder + "roguelike.png",gEngine->getRenderer());

    space = folderSprite->height();
	
	button* rogueBut = new button(folderSprite, chosenRogue);
	rogueBut->setHoverCallback(hoverOver);
	
	rogue.addComponent(rogueBut);

    rogue.x = gEngine->screenWidth() / 5;
    rogue.y = gEngine->screenHeight() / 4;

	textSprite* rogueT = new textSprite("Roguelike-lite",font,col,gEngine->getRenderer());
	rogueText.addComponent(rogueT);

	rogueText.x = rogue.x;
	rogueText.y = rogue.y - space;

	// rpgs

	sprite* folderSprite1  = new sprite(iconFolder + "rpg-icon.png",gEngine->getRenderer());
	
	button* rpgBut = new button(folderSprite1, chosenRPG);
    rpgBut->setHoverCallback(hoverOver);
	
    rpgs.addComponent(rpgBut);

    rpgs.x = gEngine->screenWidth() / 5 * 2;
    rpgs.y = gEngine->screenHeight() / 4;

	textSprite* rpgT = new textSprite("RPGs",font,col,gEngine->getRenderer());
    rpgText.addComponent(rpgT);

    rpgText.x = rpgs.x;
    rpgText.y = rpgs.y - space;
	
	// stealth

	sprite* folderSprite2  = new sprite(iconFolder+"stealth-icon.png",gEngine->getRenderer());
	
	button* stealthBut = new button(folderSprite2, chosenStealth);
    stealthBut->setHoverCallback(hoverOver);
	
    stealth.addComponent(stealthBut);

    stealth.x = gEngine->screenWidth() / 5 * 3;
    stealth.y = gEngine->screenHeight() / 4;

	textSprite* stealthT = new textSprite("Stealth",font,col,gEngine->getRenderer());
    stealthText.addComponent(stealthT);

    stealthText.x = stealth.x;
    stealthText.y = stealth.y - space;

	// platformer
	
	sprite* folderSprite3  = new sprite(iconFolder+"platformer.png",gEngine->getRenderer());
	
	button* platformerBut = new button(folderSprite3, chosenPlatformer);
    platformerBut->setHoverCallback(hoverOver);
	
    platformer.addComponent(platformerBut);

    platformer.x = gEngine->screenWidth() / 5 * 4;
    platformer.y = gEngine->screenHeight() / 4;

	textSprite* platformerT = new textSprite("Platformer",font,col,gEngine->getRenderer());
    platformerText.addComponent(platformerT);

    platformerText.x = platformer.x;
    platformerText.y = platformer.y - space;


	// fighting

	sprite* folderSprite7  = new sprite(iconFolder + "fighting-icon.png",gEngine->getRenderer());
	
	button* fightingBut = new button(folderSprite7, chosenFighting);
    fightingBut->setHoverCallback(hoverOver);
	
    fighting.addComponent(fightingBut);

    fighting.x = gEngine->screenWidth() / 5;
    fighting.y = gEngine->screenHeight() / 4 * 2;

	textSprite* fightingT = new textSprite("Fighting",font,col,gEngine->getRenderer());
    fightingText.addComponent(fightingT);

    fightingText.x = fighting.x;
    fightingText.y = fighting.y - space;	

	// aprgs

	sprite* folderSprite4  = new sprite(iconFolder + "arpgs.png",gEngine->getRenderer());
	
	button* arpgBut = new button(folderSprite4, chosenARPG);
    arpgBut->setHoverCallback(hoverOver);
	
    arpg.addComponent(arpgBut);

    arpg.x = gEngine->screenWidth() / 5 * 2;
    arpg.y = gEngine->screenHeight() / 4 * 2;

	textSprite* arpgT = new textSprite("ARPGs",font,col,gEngine->getRenderer());
    arpgText.addComponent(arpgT);

    arpgText.x = arpg.x;
    arpgText.y = arpg.y - space;

	// strategy

	sprite* folderSprite5  = new sprite(iconFolder + "strategy.png",gEngine->getRenderer());
	
	button* strategyBut = new button(folderSprite5, chosenStrategy);
    strategyBut->setHoverCallback(hoverOver);
	
    strategy.addComponent(strategyBut);

    strategy.x = gEngine->screenWidth() / 5 * 3;
    strategy.y = gEngine->screenHeight() / 4 * 2;

	textSprite* strategyT = new textSprite("Strategy",font,col,gEngine->getRenderer());
    strategyText.addComponent(strategyT);

    strategyText.x = strategy.x;
    strategyText.y = strategy.y - space;

	// racing
	
	sprite* folderSprite6  = new sprite(iconFolder + "race-icon.png",gEngine->getRenderer());
	
	button* racingBut = new button(folderSprite6, chosenRacing);
    racingBut->setHoverCallback(hoverOver);
	
    racing.addComponent(racingBut);

    racing.x = gEngine->screenWidth() / 5 * 4;
    racing.y = gEngine->screenHeight() / 4 * 2;

	textSprite* racingT = new textSprite("Racing",font,col,gEngine->getRenderer());
    racingText.addComponent(racingT);

    racingText.x = racing.x;
    racingText.y = racing.y - space;


	// simulator

	sprite* folderSprite8  = new sprite(iconFolder + "simulator-icon.png",gEngine->getRenderer());
	
	button* simulatorBut = new button(folderSprite8, chosenSimulator);
    simulatorBut->setHoverCallback(hoverOver);
	
    simulator.addComponent(simulatorBut);

    simulator.x = gEngine->screenWidth() / 5;
    simulator.y = gEngine->screenHeight() / 4 * 3;

	textSprite* simulatorT = new textSprite("Simulator",font,col,gEngine->getRenderer());
    simulatorText.addComponent(simulatorT);

    simulatorText.x = simulator.x;
    simulatorText.y = simulator.y - space;

	// puzzle

	sprite* folderSprite9  = new sprite(iconFolder + "puzzle-icon.png",gEngine->getRenderer());
	
	button* puzzleBut = new button(folderSprite9, chosenPuzzle);
    puzzleBut->setHoverCallback(hoverOver);
	
    puzzle.addComponent(puzzleBut);

    puzzle.x = gEngine->screenWidth() / 5 * 2;
    puzzle.y = gEngine->screenHeight() / 4 * 3;

	textSprite* puzzleT = new textSprite("Puzzle",font,col,gEngine->getRenderer());
    puzzleText.addComponent(puzzleT);

    puzzleText.x = puzzle.x;
    puzzleText.y = puzzle.y - space;

	// example

	sprite* folderSprite10  = new sprite(iconFolder + "example-icon.png",gEngine->getRenderer());
	
	button* exampleBut = new button(folderSprite10, chosenExample);
    exampleBut->setHoverCallback(hoverOver);
	
    example.addComponent(exampleBut);

    example.x = gEngine->screenWidth() / 5 * 4;
    example.y = gEngine->screenHeight() / 4 * 3;

	textSprite* exampleT = new textSprite("Example",font,col,gEngine->getRenderer());
    exampleText.addComponent(exampleT);

    exampleText.x = example.x;
    exampleText.y = example.y - space;
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

	platformerText.update(gEngine,deltaTime);
	platformer.update(gEngine,deltaTime);

	arpgText.update(gEngine,deltaTime);
	arpg.update(gEngine,deltaTime);

    strategyText.update(gEngine,deltaTime);
    strategy.update(gEngine,deltaTime);

	fightingText.update(gEngine,deltaTime);
	fighting.update(gEngine,deltaTime);

    racingText.update(gEngine,deltaTime);
	racing.update(gEngine,deltaTime);

    exampleText.update(gEngine,deltaTime);
    example.update(gEngine,deltaTime);

    simulatorText.update(gEngine,deltaTime);
    simulator.update(gEngine,deltaTime);

    puzzleText.update(gEngine,deltaTime);
    puzzle.update(gEngine,deltaTime);

	exampleText.update(gEngine,deltaTime);
	example.update(gEngine,deltaTime);
	
	SDL_RenderPresent(gEngine->getRenderer());
}

void chooseState::chosenRogue(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("roguelike-lite");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenExample(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("example");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenPuzzle(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("puzzle");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenSimulator(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("simulator");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenRacing(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("racing");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenFighting(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("fighting");
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

void chooseState::chosenPlatformer(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("platformer");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenARPG(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("arpgs");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
}

void chooseState::chosenStrategy(engine* gEngine)
{
	inGameState* inG = (inGameState*) gEngine->getState(inGame);

	inG->setPath("strategy");
	inG->init(gEngine);
	
	gEngine->changeGameState(inGame);
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
