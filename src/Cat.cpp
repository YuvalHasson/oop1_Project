#include "Cat.h"

Cat::Cat(Vertex loc, Size size, int speed)
	:MovingObject(loc, size, speed)
{
	this->setSprite(TEXTURE::cat);
	this->setLocation(this->getSprite().getPosition());
}

void Cat::move(sf::Time deltaTime)
{
	this->setLastLocation(this->getLocation());

	this->directionRight();
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

	this->setLocation(this->getSprite().getPosition());

}

void Cat::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

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
