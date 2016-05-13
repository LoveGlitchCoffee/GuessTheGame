#include "button.h"

button::button(sprite* image, void (*action)(engine* gEngine))
{
	// button may have up to 2 components, a standard image and a image when interacting
	subComponents.reserve(2);

	// pointer gets deleted?
	subComponents.push_back(image);
	
	sprite* buttonImage = (sprite*) subComponents.at(0);
	buttonWidth = buttonImage->width();
	buttonHeight = buttonImage->height();
	//Only callback function is required
	callbackFunc = action;

	//all other callbacks are optional and null by default
	hoverFunc = nullptr;
}

void button::update(engine* gEngine, float deltaTime)
{
	if (gEngine->event()->type == SDL_MOUSEMOTION)
	{
		int mouseX,mouseY;
		SDL_GetMouseState(&mouseX,&mouseY);
		
		//printf("mouse position: %d %d\n", mouseX, mouseY);
		
		if (withinBoundary(mouseX,mouseY))		
			mouseWithinBoundary = true;
		else
			mouseWithinBoundary = false;

		if (hoverFunc != nullptr)
			hoverFunc(this);		
	}
	
	if (gEngine->event()->type == SDL_MOUSEBUTTONUP)
	{
		bool clicked = false;;
		
		int mouseX,mouseY;
		SDL_GetMouseState(&mouseX,&mouseY);

		if (withinBoundary(mouseX,mouseY))
			clicked = true;
		   
		if (clicked)
			callbackFunc(gEngine);
	}

	for (auto &it : subComponents)
	{
		it->update(gEngine, deltaTime);
	}	
}

bool button::withinBoundary(int mouseX, int mouseY)
{
	return mouseX >= gObject->x - buttonWidth/2 && mouseX <= gObject->x + buttonWidth/2 &&
		mouseY >= gObject->y - buttonHeight/2 && mouseY <= gObject->y + buttonHeight/2;
}


void button::setHoverCallback(void (*action)(button* refButton))
{
	hoverFunc = action;
}

bool button::mouseOnButton()
{
	return mouseWithinBoundary;
}
