#include "Mouse.h"
#include <iostream>


Mouse::Mouse(Vertex loc, Size size, int lives, int keys, int speed)
	:MovingObject(loc, size, speed), m_lives(lives), m_keys(keys)
{
	this->setSprite(TEXTURE::mouse);
	this->setLocation(this->getSprite().getPosition());
}

void Mouse::move(sf::Time deltaTime)
{
	this->setLastLocation(this->getLocation());
	//std::cout << this->getLastLocation().m_x << " " << this->getLastLocation().m_y << std::endl;

	auto s = this->getSize().m_x / 380;
	auto origin = sf::Vector2f(this->getSprite().getTexture()->getSize() / 2u);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->directionUp();
		this->getSprite().setOrigin(origin);
		this->getSprite().setRotation(90.f);
		this->getSprite().setScale(-s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->directionDown();
		this->getSprite().setOrigin(origin);
		this->getSprite().setRotation(270.f);
		this->getSprite().setScale(-s, -s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->directionRight();
		this->getSprite().setOrigin(origin);
		this->getSprite().setRotation(0.f);
		this->getSprite().setScale(s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->directionLeft();
		this->getSprite().setOrigin(origin);
		this->getSprite().setRotation(180.f);
		this->getSprite().setScale(s, -s);
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

void Mouse::handleCollision(Wall& wall)
{
	this->setLocation(this->getLastLocation());
	this->getSprite().setPosition(this->getLastLocation());

	//std::cout << "m Loc: " << this->getSprite().getPosition().x << " " << this->getSprite().getPosition().y << std::endl;
	//std::cout << "wall loc: " << wall.getSprite().getPosition().x << " " << wall.getSprite().getPosition().y << std::endl;
	//
	//auto a = (wall.getSize().m_x / 380) / 4; // the size of paremeter that we wnat to hendell collitions
	//auto b = sqrt((a * a) + (a * a));

	//auto x_mouse = this->getSprite().getGlobalBounds().left;
	//auto x_wall = wall.getSprite().getGlobalBounds().left + wall.getSprite().getGlobalBounds().width;
	//auto moveIn = x_wall - x_mouse;

	//if (moveIn <=0 || moveIn <= a) // mouse_right x <= wall_left x
	//{
	//	std::cout << " in here " << std::endl;
	//	this->getSprite().setPosition(this->getSprite().getPosition().x , this->getSprite().getPosition().y + moveIn);
	//}
	//if (this->getSprite().getPosition().x - wall.getSprite().getPosition().x >= a) // mouse x >= wall x
	//{
	//	std::cout << " in here " << wall.getSprite().getGlobalBounds().left << std::endl;
	//	
	//	//this->getSprite().setPosition(this->getSprite().getPosition().x, this->getSprite().getPosition().y - 10.f);
	//}
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
