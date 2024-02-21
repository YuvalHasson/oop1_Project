#include "Mouse.h"
#include <iostream>


Mouse::Mouse(Vertex loc, Size size, int lives, int keys, int speed)
	:MovingObject(loc, size, speed), m_lives(lives), m_keys(keys)
{
	this->setSprite(TEXTURE::mouse);
	this->setLocation(this->getSprite().getPosition());
}

Mouse::~Mouse()
{
}

void Mouse::move(sf::Time deltaTime)
{
	this->setLastLocation(this->getLocation());
	//std::cout << this->getLastLocation().m_x << " " << this->getLastLocation().m_y << std::endl;

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
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

	this->setLocation(this->getSprite().getPosition());
	
	this->resetDirection();
}

void Mouse::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
	std::cout << "me?" << std::endl;

}

void Mouse::handleCollision(Cat&)
{
	std::cout << "cat" << std::endl;

}

void Mouse::handleCollision(Cheese&)
{
	std::cout << "c" << std::endl;

}

void Mouse::handleCollision(Wall&)
{
	std::cout << this->getLastLocation().x << " " << this->getLastLocation().y << std::endl;
	this->setLocation(this->getLastLocation());
	this->getSprite().setPosition(this->getLastLocation());
}

void Mouse::handleCollision(Key&)
{
	std::cout << "key" << std::endl;
}

void Mouse::handleCollision(Door&)
{
	std::cout << "d" << std::endl;
}

void Mouse::handleCollision(Present&)
{
	std::cout << "p" << std::endl;

}
