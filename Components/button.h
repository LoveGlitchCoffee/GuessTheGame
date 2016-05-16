#pragma once

#include "../GameEngine/engine.h"
#include "../GameEngine/component.h"
#include "sprite.h"

class button : public component
{
public:

	/** 
	 * @brief checks if the mouse has moved within the boundary of the button or clicked the button
	 * 
	 * @param gEngine the game engine
	 * @param deltaTime the time that has passed since the last update()
	 */
	void update(engine* gEngine, float deltaTime);

	/** 
	 * @brief the button is initialised with an image and a callback function
	 *        the callback function will be policy class function (static) of the game state
	 * 
	 * @param image the image of the button
	 * @param action the callback function
	 * 
	 */
	button(sprite* image, void (*action)(engine*));

	/** 
	 * @brief set the callback function when mouse hover over the button
	 * 
	 * @param action the hover callback
	 */
	void setHoverCallback(void (*action)(button*));    

	/** 
	 * @brief returns if the mouse is over the button
	 * 
	 * @return whether the mouse is over the button
	 */
	bool mouseOnButton();
	
private:

	/** 
	 * @brief checks if the mouse is within the boundary of the button
	 * 
	 * @param mouseX the mouse x position
	 * @param mouseY the mouse y position
	 * 
	 * @return whether the mouse is within the button's boundary
	 */
	bool withinBoundary(int mouseX, int mouseY);
	
	void (*callbackFunc)(engine*);

	void (*hoverFunc)(button*);
	
	int buttonWidth, buttonHeight;
	bool mouseWithinBoundary;
	bool clicked;
};
