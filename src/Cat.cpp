#include "Cat.h"
#include <iostream>

bool Cat::m_freeze = false;

Cat::Cat(Vertex loc, Size size, int speed)
	:MovingObject(loc, size, speed)
{
	this->setSprite(TEXTURE::cat);
	this->setLocation(this->getSprite().getPosition());
	this->setStarterLocation(this->getLocation());
}

void Cat::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Cat::handleCollision(Mouse&) {}

void Cat::handleCollision(Wall&)
{
	this->setLocation(this->getLastLocation());
	this->getSprite().setPosition(this->getLastLocation());
}

void Cat::handleCollision(Door&)
{
	this->setLocation(this->getLastLocation());
	this->getSprite().setPosition(this->getLastLocation());
}

void Cat::handleCollision(Cat& cat)
{
	if (this != &cat)
	{
		this->setLocation(this->getLastLocation());
		this->getSprite().setPosition(this->getLastLocation());
		this->getMetWall();
	}
}

void Cat::setFreeze(bool freeze)
{
	m_freeze = freeze;
}

void Cat::updateMetWall()
{
	if (m_isMetWall)
	{
		this->m_isMetWall = false;
	}
	else
	{
		this->m_isMetWall = true;
	}
}

bool Cat::getFreeze()
{
	return m_freeze;
}

bool Cat::getMetWall()
{
	return this->m_isMetWall;
}
