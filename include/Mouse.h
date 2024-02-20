#pragma once

#include "MovingObjects.h"

class Mouse : public MovingObject
{
private:
	int m_lives;
	int m_keys;

public:
	Mouse(Vertex, Size, int, int);
	virtual ~Mouse();

	//move
	virtual void move(sf::Time);

};