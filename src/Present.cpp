#include "Present.h"

int Present::m_presents = 0;

Present::Present(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::present);
	++m_presents;
}

Present::~Present()
{
	--m_presents;
}

int Present::getPresents()
{
	return m_presents;
}
