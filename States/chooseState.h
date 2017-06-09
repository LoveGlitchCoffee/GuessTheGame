#pragma once

#include <unordered_map>

#include "../States/inGameState.h"
#include "../GameEngine/engine.h"
#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "../Components/sprite.h"
#include "../Components/button.h"
#include "../Components/textSprite.h"

class chooseState : public gameState
{
public:
	
	chooseState(engine* gEngine);
	~chooseState();
	
	void init(engine* gEngine);

	void close();

	void handleInput(engine* gEngine, float deltaTime);

	void update(engine* gEngine, float deltaTime);

	string getFolderName();
	
private:

    std::string labels[12];
    
    std::unordered_map<std::string, gameObject*> labelTable;
    std::unordered_map<std::string, gameObject*> buttonTable;

    void createMenuItem(string iconPath, string label, void(*callback)(engine*), int x, int y);
   
	static void hoverOver(button* folder);    

	TTF_Font* font;
	SDL_Color col = {0,0,0,255};

    static void coreCallback(engine* gEngine, std::string ingamePath);

	static void chosenRogue(engine* gEngine);
	static void chosenRPG(engine* gEngine);
	static void chosenStealth(engine* gEngine);
	static void chosenPlatformer(engine* gEngine);
	static void chosenARPG(engine* gEngine);
	static void chosenStrategy(engine* gEngine);
	static void chosenFighting(engine* gEngine);
	static void chosenRacing(engine* gEngine);
	static void chosenSimulator(engine* gEngine);
	static void chosenPuzzle(engine* gEngine);
    static void chosenOpenWorld(engine* gEngine);
	static void chosenExample(engine* gEngine);    

	bool canUpdate;

	string iconFolder;

    engine* engineRef;
	
};
