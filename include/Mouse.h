#pragma once

#include "MovingObjects.h"

class Mouse : public MovingObject
{
public:
	Mouse();
	virtual ~Mouse();

	//draw
	virtual void draw();

	//move
	virtual void move(MovingObject&);

	void print();

private:
	int m_lives;
	int m_keys;
};