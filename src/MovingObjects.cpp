#include "MovingObjects.h"

MovingObject::MovingObject(Vertex loc, Size size)
	:GameObject(loc, size)
{
}

MovingObject::~MovingObject()
{
}

void MovingObject::directionUp()
{
	this->m_direction = sf::Vector2f(0, -1);
}

void MovingObject::directionDown()
{
	this->m_direction = sf::Vector2f(0, 1);
}

void MovingObject::directionRight()
{
	this->m_direction = sf::Vector2f(1, 0);
}

void MovingObject::directionLeft()
{
	this->m_direction = sf::Vector2f(-1, 0);
}

void MovingObject::resetDirection()
{
	this->m_direction = sf::Vector2f(0, 0);
}

sf::Vector2f MovingObject::getDirection() const
{
	return this->m_direction;
}
