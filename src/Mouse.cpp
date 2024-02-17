#include "Mouse.h"

Mouse::Mouse()
{
	m_lives = 3;
	m_keys = 0;
}

Mouse::~Mouse()
{
}

void Mouse::draw()
{
	
}


void Mouse::move(MovingObject&)
{
}


//
void Mouse::print()
{
	//std::cout << getLocation().m_x << " " << getLocation().m_y << std::endl;
}
