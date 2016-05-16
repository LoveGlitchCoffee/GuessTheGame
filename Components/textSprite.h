#pragma once

#include "sprite.h"

class textSprite : public sprite
{	
public:

	/** 
	 * @brief derived from the sprite component but renders from a passed in string
	 * 
	 * @param text the text to render
	 * @param font the font of the text
	 * @param colour the colour of the text
	 * @param gRenderer the rendering context
	 * 
	 */
	textSprite(std::string text, TTF_Font* font,SDL_Color colour,SDL_Renderer* gRenderer);

	/** 
	 * @brief render the text if it is allowed to be rendered
	 * 
	 * @param gEngine the game engine
	 * @param deltaTime the time that has passed since the last update
	 */
	void update(engine* gEngine, float deltaTime);

	/** 
	 * @brief sets the text to be rendered or not
	 * 
	 * @param render whether or not to render the text
	 */
	void setBeingRendered(bool render);
	
private:
	
	/// font don't need to be freed because freed in state
	TTF_Font* font;
	SDL_Color colour;

	bool beingRendered;

	/** 
	 * @brief creates a sprite from text
	 *        loads a texture from a string using the specified font and colour
	 * 
	 * @param text the text to render
	 * @param gRenderer the rendering context
	 * 
	 * @return whether the sprite have been created successfully
	 */
	bool loadFromText(std::string text, SDL_Renderer* gRenderer);
};
