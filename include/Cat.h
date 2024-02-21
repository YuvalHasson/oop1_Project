#pragma once

#include "MovingObjects.h"

class Cat : public MovingObject
{
private:

public:
	Cat(Vertex, Size, int);
	virtual ~Cat();
	
	//move
	virtual void move(sf::Time);

	virtual void handleCollision(GameObject&) override;

	virtual void handleCollision(Mouse&) override {};
};
