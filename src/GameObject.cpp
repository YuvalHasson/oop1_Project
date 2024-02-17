#include "GameObject.h"

GameObject::GameObject(char objRep, double x, double y)
{
	this->m_objectRep = objRep;
	this->setLocation(x, y);
}

GameObject::~GameObject()
{
}

Vertex GameObject::getLocation() const
{
	return m_location;
}

void GameObject::draw()
{
}

void GameObject::setLocation(double x, double y)
{
	this->m_location.m_x = x;
	this->m_location.m_y = y;
}

