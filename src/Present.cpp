#include "Present.h"

Present::Present(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::present);
}

void Present::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}
