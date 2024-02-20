#include "Cat.h"

Cat::Cat(Vertex loc, Size size)
	:MovingObject(loc, size)
{
	this->setSprite(TEXTURE::cat);
}

Cat::~Cat()
{
}

void Cat::move(sf::Time deltaTime)
{
	this->getSprite().move(this->getDirection() * MouseSpeed * deltaTime.asSeconds());
}
