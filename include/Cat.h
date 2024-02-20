#pragma once

#include "MovingObjects.h"

class Cat : public MovingObject
{
private:

public:
	Cat(Vertex, Size);
	virtual ~Cat();
	
	//move
	virtual void move(sf::Time);
};
