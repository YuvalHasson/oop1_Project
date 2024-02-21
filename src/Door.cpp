#include "Door.h"

Door::Door(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::door);
}

Door::~Door()
{
}

void Door::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}
