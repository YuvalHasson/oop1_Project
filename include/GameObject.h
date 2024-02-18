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
	virtual ~GameObject();

	virtual void draw();

	//get
	virtual Vertex getLocation() const;
	virtual char getChar() const;

	//set
	virtual void setLocation(double, double);
	virtual void setChar(char);
};