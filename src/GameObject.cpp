#include "GameObject.h"

GameObject::GameObject(Vertex loc, Size size)
	:m_location(), m_size()
{
	this->setLocation(sf::Vector2f(loc.m_x, loc.m_y));
	this->setSize(size);
}

sf::Vector2f GameObject::getLocation() const
{
	return m_location;
}

Size GameObject::getSize() const
{
	return this->m_size;
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
	float s = this->getSize().m_x / 380.f;
	float x = this->getLocation().x;
	float y = this->getLocation().y;

	this->m_sprite.setTexture(*Rescources::getResource().getTexture(obj));
	this->m_sprite.setScale(s, s);
	this->m_sprite.setOrigin(sf::Vector2f(this->getSprite().getTexture()->getSize() / 2u));
	this->m_sprite.setPosition(sf::Vector2f(x * (this->getSize().m_x + 1) + this->getSize().m_x / 2 + 10,
		y * (this->getSize().m_x + 1) + 60));
}

bool GameObject::collidesWith(const GameObject& obj)
{
	//auto a = sf::FloatRect(this->m_sprite.getGlobalBounds().left, this->m_sprite.getGlobalBounds().top,
	//	this->m_sprite.getGlobalBounds().width, this->m_sprite.getGlobalBounds().height);
	sf::FloatRect a;
	this->getSprite().getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds(), a);

	if (a.width <= 4.5f || a.height <= 4.5f)
	{
		return false;
	}
	//return a.intersects(obj.m_sprite.getGlobalBounds());
	return true;
}
