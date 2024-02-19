#pragma once

#include "StaticObjects.h"


class Wall : public StaticObjects
{
private:
	sf::Sprite m_wall;
	sf::Texture* m_texture;
	
public:
	Wall(Vertex, Size);
	virtual ~Wall();

	//get
	virtual sf::Texture* getTexture() const;
	virtual sf::Sprite getSprite() const;

	//set
	virtual void setSprite(sf::Texture*);
};