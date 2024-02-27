#include "PresentLife.h"
#include "Mouse.h"

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
	SoundResource::getSound().playSound(SOUND::life);
	mouse.addLife();
	this->Eaten();
}
