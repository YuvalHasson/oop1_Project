#pragma once

#include "StaticObjects.h"
#include "Mouse.h"

class Door : public StaticObjects
{
private:

public:
	Door(Vertex, Size);

	virtual void handleCollision(GameObject&);
	virtual void handleCollision(Mouse&);
};