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
	
	// trying to equalize row and than col
	if (!m_isMetWall)
	{
		if (mouseLoc.y >= this->getLocation().y) // mouse is from down 
		{
			if (mouseLoc.x > this->getLocation().x + 3) // mouse is from right-down
			{
				this->directionRight();
			}
			else if (mouseLoc.x + 3 < this->getLocation().x) // mouse is from left-down
			{
				this->directionLeft();
			}
			else if (mouseLoc.x - this->getLocation().x < 3)
			{
				this->directionDown();
			}
		}
		else if (mouseLoc.y <= this->getLocation().y) // mouse is from up
		{
			if (mouseLoc.x > this->getLocation().x + 3) // mouse is from right-up
			{
				this->directionRight();
			}
			else if (mouseLoc.x + 3 < this->getLocation().x) // mouse is from left-up
			{
				this->directionLeft();
			}
			else if (mouseLoc.x - this->getLocation().x < 3)
			{
				this->directionUp();
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
			}
			else if (mouseLoc.y > this->getLocation().y + 3) // mouse is from left-down
			{
				this->directionDown();
			}
			else if (mouseLoc.y - this->getLocation().y < 3)
			{
				this->directionLeft();
			}
		}
		else if (mouseLoc.x <= this->getLocation().x) // mouse is from right
		{
			if (mouseLoc.y > this->getLocation().y + 3) // mouse is from right-Down
			{
				this->directionDown();
			}
			else if (mouseLoc.y + 3 < this->getLocation().y) // mouse is from right-up
			{
				this->directionUp();
			}
			else if (mouseLoc.y - this->getLocation().y < 3)
			{
				this->directionRight();
			}
		}
	}
	if (m_freeze)
	{
		this->resetDirection();
	}
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
