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
	return m_texture;
}

void Wall::setTexture(sf::Texture* texture)
{
	m_texture = texture;
}
