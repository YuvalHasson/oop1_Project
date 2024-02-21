#pragma once

#include "StaticObjects.h"

class Key : public StaticObjects
{
private:

public:
	Key(Vertex, Size);
	virtual ~Key();

	virtual void handleCollision(GameObject&);

};