#pragma once

#include "MovingObjects.h"

class Mouse : public MovingObject
{
private:
	int m_lives;
	int m_keys;

public:
	Mouse(Vertex, Size, int, int, int);

	//move
	virtual void move(sf::Time);
	
	virtual void handleCollision(GameObject&) override;

	virtual void handleCollision(Cat&) override;
	virtual void handleCollision(Cheese&) override;
	virtual void handleCollision(Wall&) override;
	virtual void handleCollision(Key&) override;
	virtual void handleCollision(Door&) override;
	virtual void handleCollision(Present&) override;
};