#include "Door.h"

int Door::m_door = 0;

Door::Door(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::door);
	++m_door;
}

Door::~Door()
{
	--m_door;
}

void Door::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Door::handleCollision(Mouse& other)
{
	if (other.getKeys() > 0)
	{
		this->Eaten();
	}
}

int Door::getDoor()
{
	return m_door;
}
