#include "Cat.h"

Cat::Cat(Vertex loc, Size size, int speed)
	:MovingObject(loc, size, speed)
{
	this->setSprite(TEXTURE::cat);
}

Cat::~Cat()
{
}

void Cat::move(sf::Time deltaTime)
{
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());
}

void Cat::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}
