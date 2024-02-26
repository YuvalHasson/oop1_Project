#pragma once

#include "Present.h"

//remove cat
class PresentCat : public Present
{
private:
	static bool m_presentTaken;

public:
	PresentCat(Vertex, Size);

	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Mouse&) override;

	static void setPresentTaken(bool);
	static bool getPresetnTaken();
};
