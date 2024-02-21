#include "Door.h"

Door::Door(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::door);
}

void Door::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}
