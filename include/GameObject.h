#pragma once

#include "Utilities.h"
#include <SFML/Graphics.hpp>

class GameObject
{
private:
	Vertex m_location;
	char m_objectRep;
public:
	GameObject();
	virtual ~GameObject();

	virtual void draw() = 0;

	//get
	virtual Vertex getLocation() const;
	virtual char getChar() const;
	virtual sf::Texture* getTexture() const = 0;

	//set
	virtual void setLocation(Vertex);
	virtual void setChar(char);
	virtual void setTexture(sf::Texture*) = 0;
};