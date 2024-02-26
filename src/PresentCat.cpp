#include "PresentCat.h"

#include <iostream>

bool PresentCat::m_presentTaken = false;

PresentCat::PresentCat(Vertex loc, Size size)
	:Present(loc, size)
{
}

void PresentCat::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void PresentCat::handleCollision(Mouse&)
{
	std::cout << "cat gift\n";
	setPresentTaken(true);
	this->Eaten();
}

void PresentCat::setPresentTaken(bool isTaken)
{
	m_presentTaken = isTaken;
}

bool PresentCat::getPresetnTaken()
{
	return m_presentTaken;
}
