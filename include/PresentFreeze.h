#pragma once

#include "Present.h"

class PresentFreeze : public Present
{
private:
	static bool m_presentFreeze;

public:
	PresentFreeze(Vertex, Size);

	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Mouse&) override;

	static void setPresentFreeze(bool);
	static bool getPresentFreeze();
};