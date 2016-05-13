#include "component.h"

void component::setGameObject(gameObject* object)
{
	gObject = object;
}

void component::sendMessage(string eventName)
{
	gObject->broadcast(eventName);
}

void component::receiveMessage(string eventName)
{
	handleEvent(eventName);
}

void component::handleEvent(string eventName)
{
	
}

vector<component*> component::getSubComponents()
{
	return subComponents;
}

void component::addSubComponents(component* comp)
{
	subComponents.push_back(comp);
}

string component::getKey(string eventName)
{
	bool foundKey = false;
	string stringbuilder;

	int counter = 0;
	
	while (counter < eventName.size() && !foundKey)
	{
		//printf("getting char %c\n",eventName[counter]);
		
		// 0 is false
		if (eventName[counter] != ' ')
		{
			stringbuilder.push_back(eventName[counter]);
		}
		else
			foundKey = true;
				
		++counter;
	}
	
	return stringbuilder;
}

int component::getData(string eventName, int dataNo)
{
	int returnedData = -1;
	bool foundData = false;
	
	int counter = 0;

	while (eventName[counter] != '{')
	{
		++counter;
	}

	// pass the {
	++counter;

	int dataCounter = 0;

	while (counter < eventName.size() && !foundData)
	{
		if (dataCounter == dataNo)
		{
			foundData = true;
			
			string intbuilder;
            // get everything from current till next comma or end
			while (eventName[counter] != ',' && eventName[counter] != '}')
			{
				intbuilder.push_back(eventName[counter]);
				++counter;
			}

			returnedData = std::stoi(intbuilder);
		}
		else
		{
			++dataCounter;				
			while (eventName[counter] != ',')
			{
				++counter;
			}
			++counter;
		}
	}

	if (!foundData)
	{
		perror("Cannot find data, check format: ");
		perror(eventName.c_str());		
	}
		   	
	return returnedData;
}

component::~component()
{
	// does not delete game object, not job of the component
	
	for (int i = 0; i < subComponents.size(); ++i)
	{
		delete subComponents[i];
	}
}
