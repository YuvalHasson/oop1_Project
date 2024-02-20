#pragma once

#include "GameObject.h"

class MovingObject : public GameObject
{
private:
	sf::Vector2f m_direction = sf::Vector2f(0, 0);

public:
	MovingObject(Vertex, Size);
	virtual ~MovingObject();

	//move
	virtual void move(sf::Time) = 0;

	//directions
	virtual void directionUp();
	virtual void directionDown();
	virtual void directionLeft();
	virtual void directionRight();
	virtual void resetDirection();

	//get
	virtual sf::Vector2f getDirection() const;

	//set
};