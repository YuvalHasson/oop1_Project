#pragma once

#include "StaticObjects.h"


class Wall : public StaticObjects
{
private:
	sf::Texture* m_texture;
	
public:
	Wall(Vertex, Size);
	virtual ~Wall();

	//get
	virtual sf::Texture* getTexture() const;

	//set
	virtual void setTexture(sf::Texture*);
};