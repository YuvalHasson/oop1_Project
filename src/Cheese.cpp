#include "Cheese.h"

Cheese::Cheese(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::cheese);
}

void Cheese::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}
