#include "MovingObjects.h"

MovingObject::MovingObject(Vertex loc, Size size, int speed)
	:GameObject(loc, size), m_speed(speed), m_lastLocation()
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

float MovingObject::getSpeed() const
{
	return this->m_speed;
}

sf::Vector2f MovingObject::getLastLocation() const
{
	return this->m_lastLocation;
}

void MovingObject::setLastLocation(sf::Vector2f loc)
{
	this->m_lastLocation = loc;
}
