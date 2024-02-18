#include "GameObject.h"

GameObject::GameObject()
	:m_location(), m_objectRep()
{
}

GameObject::~GameObject()
{
}

Vertex GameObject::getLocation() const
{
	return m_location;
}

char GameObject::getChar() const
{
	return this->m_objectRep;
}

void GameObject::draw()
{
}

void GameObject::setLocation(Vertex v)
{
	this->m_location.m_x = v.m_x;
	this->m_location.m_y = v.m_y;
}

void GameObject::setChar(char obj)
{
	this->m_objectRep = obj;
}

