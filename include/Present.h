#pragma once

#include "StaticObjects.h"

class Present : public StaticObjects
{
private:

public:
	Present(Vertex, Size);
	virtual ~Present();

	virtual void handleCollision(GameObject&);

};