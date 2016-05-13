#include "gameObject.h"
#include "component.h"


gameObject::gameObject()
{
	x = 0;
	y = 0;
	components.reserve(3);	
}

gameObject::~gameObject()
{
	for (int i = 0; i < components.size(); ++i)
	{
		delete components[i];
	}
}

void gameObject::addComponent(component *comp)
{
	components.push_back(comp);
	comp->setGameObject(this);

	if (comp->getSubComponents().size() > 0)
	{
		for (auto &it : comp->getSubComponents())
		{
			it->setGameObject(this);
		}
	}
		
}

void gameObject::update(engine *gEngine, float deltaTime)
{
	// remember must be reference or else it'll be by value
		
	for (auto &it : components)
	{
		it->update(gEngine,deltaTime);
	}
}

void gameObject::broadcast(string eventName)
{
	for (auto &it: components)
	{
		//printf("broadcasting %s\n", eventName.c_str());
		it->receiveMessage(eventName);
	}
}

// use int for now, switch to id later
component* gameObject::getComponent(int index)
{
	return components.at(index);
}
