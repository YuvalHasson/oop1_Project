#include "DumbCat.h"

DumbCat::DumbCat(Vertex loc, Size size, int speed)
	:Cat(loc, size, speed)
{
	srand(time(NULL));
}

void DumbCat::move(sf::Time deltaTime)
{
	
	int randNumber = 4;

	if (int randomTimeDirection; (randomTimeDirection = rand() % 20) == 10)
	{
		randNumber = rand() % 4;
	}

	this->setLastLocation(this->getLocation());

	switch (randNumber)
	{
	case 0:
		this->directionDown();
		break;
	case 1:
		this->directionLeft();
		break;
	case 2:
		this->directionRight();
		break;
	case 3:
		this->directionUp();
		break;
	default:
		break;
	}


	if (Cat::getFreeze())
	{
		this->resetDirection();
	}
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

	this->setLocation(this->getSprite().getPosition());
}
