#include "Cat.h"
#include <iostream>

bool Cat::m_freeze = false;

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
	auto s = this->getSize().m_x / 380;
	
	// trying to equalize row and than col
	if (!m_isMetWall)
	{
		if (mouseLoc.y >= this->getLocation().y) // mouse is from down 
		{
			if (mouseLoc.x > this->getLocation().x + 3) // mouse is from right-down
			{
				this->directionRight();
				this->getSprite().setRotation(0.f);
				this->getSprite().setScale(s, s);
			}
			else if (mouseLoc.x + 3 < this->getLocation().x) // mouse is from left-down
			{
				this->directionLeft();
				this->getSprite().setRotation(180.f);
				this->getSprite().setScale(s, -s);
			}
			else if (mouseLoc.x - this->getLocation().x < 3)
			{
				this->directionDown();
				this->getSprite().setRotation(270.f);
				this->getSprite().setScale(-s, -s);
			}
		}
		else if (mouseLoc.y <= this->getLocation().y) // mouse is from up
		{
			if (mouseLoc.x > this->getLocation().x + 3) // mouse is from right-up
			{
				this->directionRight();
				this->getSprite().setRotation(0.f);
				this->getSprite().setScale(s, s);
			}
			else if (mouseLoc.x + 3 < this->getLocation().x) // mouse is from left-up
			{
				this->directionLeft();
				this->getSprite().setRotation(180.f);
				this->getSprite().setScale(s, -s);
			}
			else if (mouseLoc.x - this->getLocation().x < 3)
			{
				this->directionUp();
				this->getSprite().setRotation(90.f);
				this->getSprite().setScale(-s, s);
			}
		}
	}
	// trying to equalize col and than row
	else
	{
		if (mouseLoc.x >= this->getLocation().x) // mouse is from left 
		{
			if (mouseLoc.y + 3 < this->getLocation().y) // mouse is from left-up
			{
				this->directionUp();
				this->getSprite().setRotation(90.f);
				this->getSprite().setScale(-s, s);
			}
			else if (mouseLoc.y > this->getLocation().y + 3) // mouse is from left-down
			{
				this->directionDown();
				this->getSprite().setRotation(270.f);
				this->getSprite().setScale(-s, -s);
			}
			else if (mouseLoc.y - this->getLocation().y < 3)
			{
				this->directionLeft();
				this->getSprite().setRotation(180.f);
				this->getSprite().setScale(s, -s);
			}
		}
		else if (mouseLoc.x <= this->getLocation().x) // mouse is from right
		{
			if (mouseLoc.y > this->getLocation().y + 3) // mouse is from right-Down
			{
				this->directionDown();
				this->getSprite().setRotation(270.f);
				this->getSprite().setScale(-s, -s);
			}
			else if (mouseLoc.y + 3 < this->getLocation().y) // mouse is from right-up
			{
				this->directionUp();
				this->getSprite().setRotation(90.f);
				this->getSprite().setScale(-s, s);
			}
			else if (mouseLoc.y - this->getLocation().y < 3)
			{
				this->directionRight();
				this->getSprite().setRotation(0.f);
				this->getSprite().setScale(s, s);
			}
		}
	}
	if (m_freeze)
	{
		this->resetDirection();
	}
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

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

void Cat::setFreeze(bool freeze)
{
	m_freeze = freeze;
}

void Cat::updateMetWall()
{
	if (m_isMetWall)
	{
		this->m_isMetWall = false;
	}
	else
	{
		this->m_isMetWall = true;
	}
}

bool Cat::getFreeze()
{
	return m_freeze;
}
