#pragma once

#include "GameObject.h"

class StaticObjects : public GameObject
{
private:
	bool m_isEaten;
public:
	StaticObjects(Vertex, Size);

	bool isEaten() const;
	void Eaten();

	virtual void handleCollision(GameObject&) {};
	virtual void handleCollision(Wall&) {};
	virtual void handleCollision(Mouse&) {};
	virtual void handleCollision(Cat&) {};
	virtual void handleCollision(Cheese&) {};
	virtual void handleCollision(Door&) {};
	virtual void handleCollision(Key&) {};
	virtual void handleCollision(Present&) {};

};