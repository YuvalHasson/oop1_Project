#pragma once

#include "Present.h"

//addTime
class PresentTime : public Present
{
private:
	static bool m_presentTime;

public:
	PresentTime(Vertex, Size);

	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Mouse&) override;

	static void setPresentTime(bool);
	static bool getPresentTime();
};