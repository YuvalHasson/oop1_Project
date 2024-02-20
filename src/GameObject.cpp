#include "GameObject.h"

GameObject::GameObject(Vertex loc, Size size)
	:m_location(), m_size()
{
	this->setLocation(loc);
	this->setSize(size);
}

GameObject::~GameObject()
{
}

Vertex GameObject::getLocation() const
{
	return m_location;
}

Size GameObject::getSize() const
{
	return this->m_size;
}

sf::Texture* GameObject::getTexture() const
{
	return this->m_texture;
}

sf::Sprite& GameObject::getSprite()
{
	return this->m_sprite;
}

void GameObject::setLocation(Vertex loc)
{
	this->m_location = loc;
}

void GameObject::setSize(Size size)
{
	this->m_size = size;
}

void GameObject::setSprite(int obj)
{
	float s = this->getSize().m_x / 380;
	float x = this->getLocation().m_x;
	float y = this->getLocation().m_y;
	//std::cout << x << " " << y;

	this->m_texture = Rescources::getResource().getTexture(obj);
	this->m_sprite.setTexture(*(this->m_texture));
	this->m_sprite.setScale(s, s);
	this->m_sprite.setPosition(sf::Vector2f(this->getSize().m_x * x, this->getSize().m_x * y));

	
}
