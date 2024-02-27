#pragma once

#include "StaticObjects.h"
#include "Mouse.h"

class Door : public StaticObjects
{
private:
	static int m_door;

public:
	Door(Vertex, Size);
	~Door();

	virtual void handleCollision(GameObject&);
	virtual void handleCollision(Mouse&);

	static int getDoor();
};