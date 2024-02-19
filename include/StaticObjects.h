#pragma once

#include "GameObject.h"

class StaticObjects : public GameObject
{
private:

public:
	StaticObjects(Vertex, Size);
	virtual ~StaticObjects();
};