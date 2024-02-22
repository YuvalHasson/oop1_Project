#pragma once

#include "StaticObjects.h"

class Cheese : public StaticObjects
{
private:
	static int m_cheese;

public:
	Cheese(Vertex, Size);
	virtual ~Cheese();

	virtual void handleCollision(GameObject&);
	virtual void handleCollision(Mouse&);

	static int getCheese();
};