#include "Mouse.h"
#include <iostream>

Mouse::Mouse(Vertex loc, Size size, int lives, int speed)
	:MovingObject(loc, size, speed), m_lives(lives), m_keys(0)
{
	this->setSprite(TEXTURE::mouse);
	this->setLocation(this->getSprite().getPosition());
	this->setStarterLocation(this->getLocation());
}

void Mouse::move(sf::Time deltaTime)
{
	this->setLastLocation(this->getLocation());
	//std::cout << this->getLastLocation().x << " " << this->getLastLocation().y << std::endl;

	auto s = this->getSize().m_x / 380;

	this->getSprite().setOrigin(sf::Vector2f(this->getSprite().getTexture()->getSize() / 2u));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->directionUp();
		this->getSprite().setRotation(90.f);
		this->getSprite().setScale(-s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->directionDown();
		this->getSprite().setRotation(270.f);
		this->getSprite().setScale(-s, -s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->directionRight();
		this->getSprite().setRotation(0.f);
		this->getSprite().setScale(s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->directionLeft();
		this->getSprite().setRotation(180.f);
		this->getSprite().setScale(s, -s);
	}
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

	this->setMouseLocation(this->getLocation());

	this->setLocation(this->getSprite().getPosition());
	
	this->resetDirection();
}

void Mouse::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Mouse::handleCollision(Cat&)
{
	--this->m_lives;
	this->setResetLocation();
	std::cout << "cat" << std::endl;
}

void Mouse::handleCollision(Cheese&)
{
	std::cout << "c" << std::endl;
}

void Mouse::handleCollision(Wall&)
{
	this->setLocation(this->getLastLocation());
	this->getSprite().setPosition(this->getLastLocation());
}

void Mouse::handleCollision(Key& key)
{
	std::cout << "key" << std::endl;
	++this->m_keys;
}

void Mouse::handleCollision(Door&)
{
	std::cout << "d" << std::endl;
	if (this->m_keys > 0)
	{
		--this->m_keys;
	}
	else
	{
		this->setLocation(this->getLastLocation());
		this->getSprite().setPosition(this->getLastLocation());
	}
}

void Mouse::handleCollision(Present&)
{
	std::cout << "p" << std::endl;

}

int Mouse::getKeys() const
{
	return this->m_keys;
}

int Mouse::getLives() const
{
	return this->m_lives;
}
