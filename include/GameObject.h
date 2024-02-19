#pragma once

#include "Utilities.h"
#include <SFML/Graphics.hpp>

class GameObject
{
private:
	Vertex m_location;
	Size m_size;
	
public:
	GameObject(Vertex, Size);
	virtual ~GameObject();

	//get
	virtual Vertex getLocation() const;
	virtual Size getSize() const;
	virtual sf::Texture* getTexture() const = 0;
	virtual sf::Sprite getSprite() const = 0;

	//set
	virtual void setLocation(Vertex);
	virtual void setSize(Size);
	virtual void setSprite(sf::Texture*) = 0;
};