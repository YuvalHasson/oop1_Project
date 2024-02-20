#pragma once

#include "Utilities.h"
#include "Resources.h"

#include <SFML/Graphics.hpp>

class GameObject
{
private:
	sf::Sprite m_sprite;
	sf::Texture* m_texture;

	Vertex m_location;
	Size m_size;
	
public:
	GameObject(Vertex, Size);
	virtual ~GameObject();

	//get
	virtual Vertex getLocation() const;
	virtual Size getSize() const;
	virtual sf::Texture* getTexture() const;
	virtual sf::Sprite& getSprite();

	//set
	virtual void setLocation(Vertex);
	virtual void setSize(Size);
	virtual void setSprite(int);
};