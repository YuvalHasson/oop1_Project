#pragma once

#include "MovingObjects.h"

class Mouse : public MovingObject
{
private:
	sf::Sprite m_mouse;
	sf::Texture* m_texture;

	int m_lives;
	int m_keys;

public:
	Mouse(Vertex, Size, float, int, int);
	virtual ~Mouse();

	//move
	virtual void move(sf::Time);

	//get
	virtual sf::Texture* getTexture() const;
	virtual sf::Sprite getSprite() const;

	//set
	virtual void setSprite(sf::Texture*);
};