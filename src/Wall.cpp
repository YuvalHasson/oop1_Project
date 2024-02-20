#include "Wall.h"

Wall::Wall(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::wall);
}

Wall::~Wall()
{
}
