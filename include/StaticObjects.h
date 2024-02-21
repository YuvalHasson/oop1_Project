#pragma once

#include "GameObject.h"

class StaticObjects : public GameObject
{
private:

public:
	StaticObjects(Vertex, Size);
	virtual ~StaticObjects();

	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Present&) {};

};