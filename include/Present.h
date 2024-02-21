#pragma once

#include "StaticObjects.h"

class Present : public StaticObjects
{
private:

public:
	Present(Vertex, Size);

	virtual void handleCollision(GameObject&);

};