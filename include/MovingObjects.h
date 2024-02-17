#pragma once

#include "GameObject.h"

class MovingObject : public GameObject
{
private:
	//TODO: mabye
public:
	using GameObject::GameObject; // using same constructor
	virtual ~MovingObject();

	//draw
	virtual void draw() = 0;

	//move
	virtual void move(MovingObject&) = 0;
};