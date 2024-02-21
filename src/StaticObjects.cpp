#include "StaticObjects.h"

StaticObjects::StaticObjects(Vertex loc, Size size)
	:GameObject(loc, size), m_isEaten(false)
{
}

bool StaticObjects::isEaten() const
{
	return this->m_isEaten;
}

void StaticObjects::Eaten()
{
	this->m_isEaten = true;
}
