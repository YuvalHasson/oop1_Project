#pragma once

#include "GameObject.h"

class MovingObject : public GameObject
{
private:
	float m_speed;

public:
	MovingObject(Vertex, Size, float);
	virtual ~MovingObject();

	//move
	virtual void move(sf::Time) = 0;

	//get
	virtual sf::Texture* getTexture() const = 0;
	virtual sf::Sprite getSprite() const = 0;

	//set
	virtual void setSprite(sf::Texture*) = 0;

};