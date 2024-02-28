#pragma once

#include "MovingObjects.h"

class Cat : public MovingObject
{
private:
	static bool m_freeze;
	bool m_isMetWall = false;

public:
	Cat(Vertex, Size, int);

	//move
	virtual void move(sf::Time) {};

	virtual void handleCollision(GameObject&) override;

	virtual void handleCollision(Mouse&) override;
	virtual void handleCollision(Wall&) override;
	virtual void handleCollision(Door&) override;
	virtual void handleCollision(Cat&) override;

	//set
	static void setFreeze(bool);
	virtual void updateMetWall();

	//get
	static bool getFreeze();
	bool getMetWall() const;
};
