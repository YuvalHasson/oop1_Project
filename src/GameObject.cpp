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

void GameObject::setLocation(Vertex loc)
{
	this->m_location = loc;
}

void GameObject::setSize(Size size)
{
	this->m_size = size;
}

