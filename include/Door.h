#pragma once

#include "StaticObjects.h"

class Door : public StaticObjects
{
private:

public:
	Door(Vertex, Size);
	virtual ~Door();

	virtual void handleCollision(GameObject&);

};