#pragma once

#include <dirent.h>
#include <string>
#include <cstdio>
#include <algorithm>

#include "../GameEngine/gameState.h"
#include "../GameEngine/gameObject.h"
#include "../Components/sprite.h"

#include "../Utils/GTimer.h"
#include "../Utils/pair.h"

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

	void setPath(string path);

	bool notClearScreen;
	
private:	

	void resetAll();

	int clearCounter;
	const int clearTime = 12;
	
	bool timeToReveal(float deltaTime);
	float currentTime;
	const float revealTime = 3;

	// runtime
	vector<int> randomSequence;
	vector<pair<int,int>> clipPosition;
	void moveImage(gameObject* image);

	int totalPoints;
	int pointLeft;

	string filePath;
	
	// init
	void getImages();
	// directory stream
	DIR *dir;
	
	struct dirent *ent;
	
	int currentImage;	

	string imageFiles[10];
	int imageCounter;
	gameObject imageObj[10];
};
