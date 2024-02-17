#pragma once

#include "Utilities.h"

class GameObject
{
private:
	Vertex m_location;
	char m_objectRep;
public:
	GameObject() = default;
	GameObject(char, double, double); //cahr and location
	virtual ~GameObject() = 0;

	virtual void draw() = 0;

	//get
	virtual Vertex getLocation() const;

	//set
	virtual void setLocation(double, double);
};