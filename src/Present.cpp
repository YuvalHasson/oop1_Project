#include "Present.h"

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

void Present::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Present::handleCollision(Mouse&)
{
	this->Eaten();
}

int Present::getPresents()
{
	return m_presents;
}

int Present::m_presents = 0;