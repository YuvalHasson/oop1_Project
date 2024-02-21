#include "GameObject.h"

GameObject::GameObject(Vertex loc, Size size)
	:m_location(), m_size()
{
	this->setLocation(sf::Vector2f(loc.m_x, loc.m_y));
	this->setSize(size);
}

GameObject::~GameObject()
{
}

sf::Vector2f GameObject::getLocation() const
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

void GameObject::setLocation(sf::Vector2f loc)
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
	float x = this->getLocation().x;
	float y = this->getLocation().y;
	//std::cout << x << " " << y;

	this->m_texture = Rescources::getResource().getTexture(obj);
	this->m_sprite.setTexture(*(this->m_texture));
	this->m_sprite.setScale(s, s);
	this->m_sprite.setPosition(sf::Vector2f(this->getSize().m_x * x, this->getSize().m_x * y));

	
}

bool GameObject::collidesWith(const GameObject& obj)
{
	return this->m_sprite.getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds());
}
