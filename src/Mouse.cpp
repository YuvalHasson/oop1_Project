#include "Mouse.h"
#include <iostream>

Mouse::Mouse(Vertex loc, Size size, float speed, int lives, int keys)
	:m_texture(), MovingObject(loc, size, speed), m_lives(lives), m_keys(keys)
{
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
	this->m_mouse.move(this->getDirection() * MouseSpeed * deltaTime.asSeconds());
	this->resetDirection();
	//this->m_mouse.move(this->getDirection() * MouseSpeed * deltaTime.asSeconds()); // how to move it dont delete it
}

sf::Texture* Mouse::getTexture() const
{
	return this->m_texture;
}

sf::Sprite Mouse::getSprite() const
{
	return this->m_mouse;
}

void Mouse::setSprite(sf::Texture* texture)
{
	float s = this->getSize().m_x / 380;
	float x = this->getLocation().m_x;
	float y = this->getLocation().m_y;
	std::cout << x << " " << y;

	this->m_texture = texture;
	this->m_mouse.setTexture(*texture);
	this->m_mouse.setScale(s,s);
	this->m_mouse.setPosition(sf::Vector2f(this->getSize().m_x * x, this->getSize().m_x * y));
	
}
