#pragma once

#include "StaticObjects.h"


class Wall : public StaticObjects
{
private:

public:
	Wall(Vertex, Size);

	virtual void handleCollision(GameObject&) override;

};