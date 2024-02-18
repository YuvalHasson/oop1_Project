#include "Mouse.h"

Mouse::Mouse()
	:m_texture()
{
	m_lives = 3;
	m_keys = 0;
}

Mouse::~Mouse()
{
}

void Mouse::draw()
{
	
}


void Mouse::move(MovingObject&)
{
}

sf::Texture* Mouse::getTexture() const
{
	return this->m_texture;
}

void Mouse::setTexture(sf::Texture* texture)
{
	this->m_texture = texture;
}
