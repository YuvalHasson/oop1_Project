#pragma once

#include "GameObject.h"

class MovingObject : public GameObject
{
private:
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	float m_speed;

	sf::Vector2f m_lastLocation;

public:
	MovingObject(Vertex, Size, int);

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
	virtual float getSpeed() const;
	virtual sf::Vector2f getLastLocation() const;

	//set
	virtual void setLastLocation(sf::Vector2f);

	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Present&) {};
};