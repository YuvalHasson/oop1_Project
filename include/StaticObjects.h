#pragma once

#include "GameObject.h"

class StaticObjects : public GameObject
{
private:

public:
	StaticObjects(Vertex, Size);
	virtual ~StaticObjects();

	//get
	virtual sf::Sprite getSprite() const = 0;

};