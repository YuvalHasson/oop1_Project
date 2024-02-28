#pragma once

#include "Cat.h"

class SmartCat : public Cat
{
private:

public:
	SmartCat(Vertex, Size, int);
	
	virtual void move(sf::Time);
};