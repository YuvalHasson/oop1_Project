#pragma once

#include "StaticObjects.h"

class Cheese : public StaticObjects
{
private:

public:
	Cheese(Vertex, Size);

	virtual void handleCollision(GameObject&);

};