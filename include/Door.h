#pragma once

#include "StaticObjects.h"
#include "Mouse.h"

class Door : public StaticObjects
{
private:
	static int m_door;

public:
	Door(Vertex, Size);
	~Door();

	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Mouse&) override;

	static int getDoor();
};