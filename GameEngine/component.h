#pragma once
#include <string>
#include <cctype>
#include "gameObject.h"

using std::string;

class component
{
public:

	/** 
	 * @brief Updates the component
	 * 
	 * @param gEngine the game engine
	 * @param deltaTime the time that has passed since the last update
	 */
	virtual void update(engine* gEngine, float deltaTime) = 0;

	/** 
	 * @brief set the game object that the instance of this component will be attached to
	 * 
	 * @param object the game object to attach to
	 */
	virtual void setGameObject(gameObject* object);

	/** 
	 * @brief receives message broadcasted by other components
	 * 
	 * @param eventName the message
	 */
	virtual void receiveMessage(string event);

	/** 
	 * @brief sends a message to all other components of the same game object of this instance
	 * 
	 * @param event the message
	 */
	virtual void sendMessage(string event);

	/** 
	 * @brief returns a pointer to the vector of sub-components of this parent component
	 * 
	 * @return the pointer to the vector of sub-components
	 */
	virtual vector<component*> getSubComponents();

	virtual void addSubComponents(component* comp);

	/** 
	 * Frees sub-components (RAII)
	 * 
	 * @return 
	 */
	virtual ~component();
	
protected:
	
	/** 
	 * @brief handles any event message received. 
	 *        each components (derived), should have its own event handling implementation
	 * @param event the event message
	 */
	virtual void handleEvent(string event);

	/** 
	 * @brief Gets the key/name of the event in the form of a c++ string for easy manipulation
	 * 
	 * @param event the event message
	 * 
	 * @return the key as a c++ string
	 */
	virtual string getKey(string event);

	/** 
	 * @brief Get the data of the event, if there is any
	 * 
	 * @param event the message
	 * @param dataNo the index of the data required
	 * 
	 * @return The data, convention is an int 
	 */
	virtual int getData(string event, int dataNo);
	
	/// do not need to free because freed elsewhere
	gameObject* gObject;
	
	vector<component*> subComponents;
};
