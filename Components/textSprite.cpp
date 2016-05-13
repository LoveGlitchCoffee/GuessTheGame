#include "textSprite.h"

textSprite::textSprite(std::string text,TTF_Font* font, SDL_Color colour, SDL_Renderer* gRenderer) : sprite::sprite(text,gRenderer)
{
	this->font = font;
	this->colour = colour;

	beingRendered = true;

	loadFromText(text,gRenderer);
}

bool textSprite::loadFromText(std::string text, SDL_Renderer* gRenderer)
{
	bool success = true;
	
	free();
   	
	SDL_Surface* loadSurface = TTF_RenderText_Solid(font, text.c_str(), colour);   
	
	if (loadSurface == nullptr)
	{
		printf("Cannot load surface from text: %s\n",TTF_GetError());
		success = false;
	}
	else
	{
		gTexture = SDL_CreateTextureFromSurface(gRenderer,loadSurface);

		if (gTexture == nullptr)
		{
			printf("Cannot convert surface to texture: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			w = loadSurface->w;
			h = loadSurface->h;			
		}

		SDL_FreeSurface(loadSurface);
	}	
		
	return success;
}

void textSprite::setBeingRendered(bool render)
{
	beingRendered = render;
}

void textSprite::update(engine* gEngine, float deltaTime)
{
	if (beingRendered)
		render(gEngine->getRenderer(),nullptr);
}
