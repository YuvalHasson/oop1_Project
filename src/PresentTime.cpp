#include "PresentTime.h"

bool PresentTime::m_presentTime = false;

PresentTime::PresentTime(Vertex loc, Size size)
	:Present(loc, size)
{
}

void PresentTime::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void PresentTime::handleCollision(Mouse&)
{
	SoundResource::getSound().playSound(SOUND::add_time);
	setPresentTime(true);
	this->Eaten();
}

void PresentTime::setPresentTime(bool isTaken)
{
	m_presentTime = isTaken;
}

bool PresentTime::getPresentTime()
{
	return m_presentTime;
}
