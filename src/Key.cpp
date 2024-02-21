#include "Key.h"

Key::Key(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::key);
}

Key::~Key()
{
}

void Key::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}
