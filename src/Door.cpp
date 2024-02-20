#include "Door.h"

Door::Door(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::door);
}

Door::~Door()
{
}
