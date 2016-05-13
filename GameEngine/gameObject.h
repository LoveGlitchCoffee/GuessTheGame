#pragma once

#include <vector>
#include <string>

#include "engine.h"

// Forward declaration of the component class
class component;

using std::vector;
using std::string;

class gameObject
{
public:
	
	/** 
	 * @brief Initialise position values, every gameObject that is created must have a position
	 * Reserve 3 component slot for each gameObject, take 3 as an average
	 * 
	 */
	gameObject();

	

	/** 
	 * @brief Frees all components associated with this object, RAII
	 * 
	 */
	~gameObject();

	/// x position of the object on the screen
    float x;
	/// y position of the object on the screen
    float y;


	/** 
	 * @brief Adds a component to this game object
	 * 
	 * @param comp a pointer to the component to be added
	 */
	void addComponent(component* comp);

	 
	/** 
	 * @brief Returns a pointer to the specified game components.
	 * NOTE: Currently have to know the exact index of the components as was added, will refactor later when needed
	 *
	 * @param int the index of the component
	 * 
	 * @return a pointer to the component at the specified index
	 */
	component* getComponent(int);

	/** 
	 * @brief Updates the game object, essentially updating all of its components
	 * 
	 * @param gEngine the game engine
	 * @param deltaTime the time that has passed since the last call to update()
	 */
	void update(engine* gEngine, float deltaTime);

	/** 
	 * @brief Broadcast a message to all the components of the game object
	 * 
	 * @param eventName the message
	 */
	void broadcast (string eventName);
	
private:
	
	//has to be ref to type cuz otherwise store copies of objects	
	vector<component*> components;
};
