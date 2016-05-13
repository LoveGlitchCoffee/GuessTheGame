#pragma once

#include <vector>

// if many components use, put in component
#include "../GameEngine/component.h"
#include "../GameEngine/gameObject.h"
#include "../GameEngine/engine.h"

using std::vector;

class sprite : public component
{
public:

	/** 
	 * @brief initialise values like width, height of the sprite to 0.
	 *        Call the loadFromFile() function to actually load the sprite
	 * 
	 * @param path the path to the actual image for the sprite
	 * @param gRenderer the rendering context
	 */
	sprite(std::string path, SDL_Renderer* gRenderer);

	/** 
	 * @brief call the free() function (RAII)
	 * 
	 */
	~sprite();
	
	/** 
	 * @brief render the sprite with the current clip (or none)
	 * 
	 * @param gEngine the game engine
	 * @param deltaTime the time that has passed since the last update
	 */
	void update(engine* gEngine, float deltaTime);

	/** 
	 * @brief copy a particular section of (or the whole) image to the renderer to render the image
	 *        uses an SDL_Rect to both specify the location,size of the sprite and the location, size on the image to clip and render
	 * 
	 * @param gRenderer the rendering context
	 * @param clip the clip to render
	 */
	void render(SDL_Renderer* gRenderer, SDL_Rect* clip);

	/** 
	 * @brief returns the width of the sprite
	 * 
	 * @return the width
	 */
	int width();

	/** 
	 * @brief returns the height of the sprite
	 * 
	 * @return the height
	 */
	int height();

	/** 
	 * @brief adds a clip section of the raw image to the list of clips maintained by the sprite
	 * 
	 * @param x the x position of the clip (top left)
	 * @param y the y position of the clip (top left)
	 * @param width the width of the clip (from top left)
	 * @param height the height of the clip (from top left)
	 */
	void addClip(int x, int y, int width, int height);

	/** 
	 * @brief sets which clip to be used
	 * 
	 * @param clip the index of the clip in the vector of clips
	 */
	void setClip(Uint32 clip);
	
private:

	/** 
	 * @brief Loads an image from the specified path
	 * 
	 * @param path the path to load the image from
	 * @param gRenderer the rendering context
	 * 
	 * @return whether loading the image was successful
	 */
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);
   
	vector<SDL_Rect> spriteClips;
	Uint32 currentClip;

protected:

	/** 
	 * @brief free the texture if it is being used (usually is)
	 * 
	 */
	void free();
	
	int w, h;
	SDL_Texture* gTexture;

	/** 
	 * @brief handles event for sprite
	 * list: "anim" changes the clip to whatever clip was in the data
	 * 
	 * @param event 
	 */
	void handleEvent(string event);
};
