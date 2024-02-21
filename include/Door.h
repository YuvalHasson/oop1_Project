#pragma once

#include "StaticObjects.h"

class Door : public StaticObjects
{
private:

public:
	Door(Vertex, Size);

	virtual void handleCollision(GameObject&);

};