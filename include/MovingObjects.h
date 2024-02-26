#pragma once

#include "GameObject.h"

class MovingObject : public GameObject
{
private:
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	float m_speed;

	sf::Vector2f m_startingLocation;
	sf::Vector2f m_lastLocation;
	static sf::Vector2f m_mouseLocation;
	static bool m_isResetLocation;

	bool m_isRemove = false;

public:
	MovingObject(Vertex, Size, int);

	void remove();
	bool isRemove() const;

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
	virtual sf::Vector2f getMouseLocation() const;
	virtual sf::Vector2f getStaterLocation() const;
	static bool isResetLocation();

	//set
	virtual void setLastLocation(sf::Vector2f);
	virtual void setMouseLocation(sf::Vector2f);
	virtual void setStarterLocation(sf::Vector2f);
	static void resetLocation();
	virtual void setResetLocation();
	virtual void setInitialLocation();

	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Present&) {};
};