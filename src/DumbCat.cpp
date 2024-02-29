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
	auto s = this->getSize().m_x / 380;
	switch (randNumber)
	{
	case 0:
		this->directionDown();
		this->getSprite().setRotation(270.f);
		this->getSprite().setScale(-s, -s);
		break;
	case 1:
		this->directionLeft();
		this->getSprite().setRotation(180.f);
		this->getSprite().setScale(s, -s);
		break;
	case 2:
		this->directionRight();
		this->getSprite().setRotation(0.f);
		this->getSprite().setScale(s, s);
		break;
	case 3:
		this->directionUp();
		this->getSprite().setRotation(90.f);
		this->getSprite().setScale(-s, s);
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
