#include "MovingObjects.h"

MovingObject::MovingObject(Vertex loc, Size size, float speed)
	:m_speed() , GameObject(loc, size)
{
}

MovingObject::~MovingObject()
{
}
