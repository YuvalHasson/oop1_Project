#include "Wall.h"

Wall::Wall(Vertex loc, Size size)
	:StaticObjects(loc, size), m_texture()
{
}

Wall::~Wall()
{
}

sf::Texture* Wall::getTexture() const
{
	return this->m_texture;
}

sf::Sprite Wall::getSprite() const
{
	return this->m_wall;
}

void Wall::setSprite(sf::Texture* texture)
{
	float s = this->getSize().m_x / 380;
	float x = this->getLocation().m_x;
	float y = this->getLocation().m_y;

	this->m_texture = texture;
	this->m_wall.setTexture(*texture);
	this->m_wall.setScale(s, s);
	this->m_wall.setPosition(sf::Vector2f(this->getSize().m_x * x, this->getSize().m_x * y));
}
