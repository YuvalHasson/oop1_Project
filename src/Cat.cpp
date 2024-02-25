#include "Cat.h"
#include <iostream>

Cat::Cat(Vertex loc, Size size, int speed)
	:MovingObject(loc, size, speed)
{
	this->setSprite(TEXTURE::cat);
	this->setLocation(this->getSprite().getPosition());
	this->setStarterLocation(this->getLocation());
}

void Cat::move(sf::Time deltaTime)
{
	this->setLastLocation(this->getLocation());

	auto mouseLoc = this->getMouseLocation();
	
	if (mouseLoc.x > this->getLocation().x)
	{
		this->directionUp();
	}
	if (mouseLoc.y > this->getLocation().y)
	{
		this->directionRight();
	}

	//this->directionRight();
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

	//std::cout << "Location: " << this->getLocation().x << " " << this->getLocation().y << std::endl;
	//std::cout << "Direction: " << this->getDirection().x << " " << this->getDirection().y << std::endl;
	//std::cout << "Speed: " << this->getSpeed() << std::endl;
	//std::cout << "DeltaTime: " << deltaTime.asSeconds() << std::endl;

	this->setLocation(this->getSprite().getPosition());

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
