#include "PresentLife.h"
#include "Mouse.h"

#include <iostream>

PresentLife::PresentLife(Vertex loc, Size size)
	:Present(loc, size)
{
}

void PresentLife::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void PresentLife::handleCollision(Mouse& mouse)
{
	mouse.addLife();

	this->Eaten();
}
