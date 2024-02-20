#include "Mouse.h"
#include <iostream>


Mouse::Mouse(Vertex loc, Size size, int lives, int keys)
	:MovingObject(loc, size), m_lives(lives), m_keys(keys)
{
	this->setSprite(TEXTURE::mouse);
}

Mouse::~Mouse()
{
}

void Mouse::move(sf::Time deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->directionUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->directionDown();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->directionRight();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->directionLeft();
	}
	this->getSprite().move(this->getDirection() * MouseSpeed * deltaTime.asSeconds());

	this->resetDirection();
	//this->m_mouse.move(this->getDirection() * MouseSpeed * deltaTime.asSeconds()); // how to move it dont delete it
}
