#include "Wall.h"

Wall::Wall(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::wall);
}

Wall::~Wall()
{
}

void Wall::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

