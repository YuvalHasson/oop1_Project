#include "PresentFreeze.h"

bool PresentFreeze::m_presentFreeze = false;

PresentFreeze::PresentFreeze(Vertex loc, Size size)
	:Present(loc, size)
{
}

void PresentFreeze::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void PresentFreeze::handleCollision(Mouse&)
{
	setPresentFreeze(true);
	this->Eaten();
}

void PresentFreeze::setPresentFreeze(bool isTaken)
{
	m_presentFreeze = isTaken;
}

bool PresentFreeze::getPresentFreeze()
{
	return m_presentFreeze;
}
