#pragma once

#include "StaticObjects.h"
#include "SoundResources.h"

class Present : public StaticObjects
{
private:
	static int m_presents;

public:
	Present(Vertex, Size);
	virtual ~Present();

	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Mouse&) {};

	static int getPresents();
};