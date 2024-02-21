#pragma once

#include "StaticObjects.h"

class Key : public StaticObjects
{
private:
	static int m_keys;

public:
	Key(Vertex, Size);
	virtual ~Key();

	virtual void handleCollision(GameObject&);

	virtual void handleCollision(Mouse&);

	static int getKeys();
};