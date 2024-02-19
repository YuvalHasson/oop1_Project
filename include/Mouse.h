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
	virtual void move(MovingObject&);

	//get
	virtual sf::Texture* getTexture() const;

	//set
	virtual void setTexture(sf::Texture*);
};