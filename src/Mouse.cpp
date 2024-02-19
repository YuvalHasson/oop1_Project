#include "Mouse.h"

Mouse::Mouse(Vertex loc, Size size, float speed, int lives, int keys)
	:m_texture(), MovingObject(loc, size, speed), m_lives(lives), m_keys(keys)
{
}

Mouse::~Mouse()
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
