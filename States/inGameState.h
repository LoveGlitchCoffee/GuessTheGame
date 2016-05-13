#pragma once

#include <dirent.h>
#include <string>

#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "../Components/sprite.h"

using std::string;

class inGameState : public gameState
{
public:

	inGameState(engine* gEngine);
	
	void init(engine* gEngine);

	~inGameState();
	
	void close();

	void handleInput(engine* gEngine, float deltaTime);

	void update(engine* gEngine, float deltaTime);
	
private:

	void getImages();
	// directory stream
	DIR *dir;
	
	struct dirent *ent;

	string imageFiles[10];
	int imageCounter;
	gameObject imageObj[10];
};
