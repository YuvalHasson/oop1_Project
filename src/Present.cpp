#include "Present.h"

Present::Present(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::present);
}

Present::~Present()
{
}
