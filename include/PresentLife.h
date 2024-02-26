#pragma once

#include "Present.h"


//add life
class PresentLife : public Present
{
private:

public:
	PresentLife(Vertex, Size);

	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Mouse&) override;
};
