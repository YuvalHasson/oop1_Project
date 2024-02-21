#include "Key.h"

Key::Key(Vertex loc, Size size)
	:StaticObjects(loc, size)
{
	this->setSprite(TEXTURE::key);
	++m_keys;
}

Key::~Key()
{
	--m_keys;
}

void Key::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Key::handleCollision(Mouse&)
{
	this->Eaten();
}

int Key::getKeys()
{
	return m_keys;
}

int Key::m_keys = 0;