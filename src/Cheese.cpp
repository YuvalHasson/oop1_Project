#include "Cheese.h"

Cheese::Cheese(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::cheese);
	++m_cheese;
}

Cheese::~Cheese()
{
	--m_cheese;
}

void Cheese::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Cheese::handleCollision(Mouse&)
{
	this->Eaten();
}

int Cheese::getCheese()
{
	return m_cheese;
}

int Cheese::m_cheese = 0;