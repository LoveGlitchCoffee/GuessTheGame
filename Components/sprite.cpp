#include "sprite.h"

// Constructor will call loadFromFile which allocates memory for the texture
sprite::sprite(std::string path, SDL_Renderer* gRenderer)
{
	w = 0;
	h = 0;
	gTexture = nullptr;

	// may use bool to exit program
	loadFromFile(path, gRenderer);

	// just take an average 5
	currentClip = 0;
	spriteClips.reserve(5);
}

bool sprite::loadFromFile(std::string path, SDL_Renderer* gRenderer)
{

	free();
   
	bool success = true;

	SDL_Surface* loadingSurface = IMG_Load(path.c_str());
	
	if (loadingSurface == nullptr)
	{
		printf("Cannot load image onto surface %s\n", IMG_GetError());
		success = false;
	}
	else
	{
		gTexture = SDL_CreateTextureFromSurface(gRenderer, loadingSurface);
		
		if (gTexture == nullptr)
		{
			printf("Cannot create texture from surface %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			w = loadingSurface->w;
			h = loadingSurface->h;
		}		
	}

	return success;
}


void sprite::update(engine *gEngine, float deltaTime)
{    
	// sprite component job should only be render, some other component handle animation
	if (spriteClips.size() > 0)
		render(gEngine->getRenderer(),&spriteClips[currentClip]);
	else
		render(gEngine->getRenderer(),NULL);	   	
}


// source rect is clip, if null mean render whole texture
void sprite::render(SDL_Renderer *gRenderer, SDL_Rect* clip)
{
	//printf("x rendered: %f\n",gObject->x - (w/2));
	//printf("y rendered: %f\n",gObject->y - (h/2));
	int x,y,width,height;
	
	if (clip != nullptr)
	{
		x = gObject->x - (clip->w/2);
		y = gObject->y - (clip->h/2);
		width = clip->w;
		height = clip->h;
	}
	else
	{
		x = gObject->x - (w/2);
		y = gObject->y - (h/2);
		width = w;
		height = h;
	}
		
	SDL_Rect renderQuad = {x,y,width,height};


	SDL_RenderCopy(gRenderer, gTexture, clip, &renderQuad);
}

void sprite::free()
{
	if (gTexture != nullptr)
	{
		SDL_DestroyTexture(gTexture);
		gTexture = nullptr;		
	}	
}

// Destructor calls the free() function which will free resources allocated
sprite::~sprite()
{
	free();
}

int sprite::width()
{
	return w;
}

int sprite::height()
{
	return h;
}

void sprite::addClip(int x, int y, int width, int height)
{
	spriteClips.push_back({x,y,width,height});
}

void sprite::handleEvent(string eventName)
{
	//printf("event received %s\n", eventName.c_str());	
	
	string key = getKey(eventName);
	
	if (key.compare("anim") == 0)
	{
		//printf("got key anim\n");
		Uint32 clip = getData(eventName, 0);		
		setClip(clip);
	}
	
}

void sprite::setClip(Uint32 clip)
{
	currentClip = clip;
}
