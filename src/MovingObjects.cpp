#include "MovingObjects.h"

sf::Vector2f MovingObject::m_mouseLocation = sf::Vector2f(0, 0);
bool MovingObject::m_isResetLocation = false;

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

sf::Vector2f MovingObject::getMouseLocation() const
{
	return this->m_mouseLocation;
}

sf::Vector2f MovingObject::getStaterLocation() const
{
	return this->m_startingLocation;
}

bool MovingObject::isResetLocation()
{
	return m_isResetLocation;
}

void MovingObject::setLastLocation(sf::Vector2f loc)
{
	this->m_lastLocation = loc;
}

void MovingObject::setMouseLocation(sf::Vector2f loc)
{
	this->m_mouseLocation = loc;
}

void MovingObject::setStarterLocation(sf::Vector2f loc)
{
	this->m_startingLocation = loc;
}

void MovingObject::resetLocation()
{
	m_isResetLocation = false;
}

void MovingObject::setResetLocation()
{
	m_isResetLocation = true;
}

void MovingObject::setInitialLocation()
{
	this->setLocation(this->getStaterLocation());
	this->getSprite().setPosition(this->getLocation());
}
