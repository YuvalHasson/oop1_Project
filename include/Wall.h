#pragma once

#include "StaticObjects.h"


class Wall : public StaticObjects
{
private:
	
public:
	Wall(Vertex, Size);
	virtual ~Wall();

	virtual void handleCollision(GameObject&) override;

	virtual void handleCollision(Mouse&) override {};
};