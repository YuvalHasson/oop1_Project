#include "Resources.h"

Rescources::Rescources()
{
	for (size_t i = 0; i < OBJ_AMOUNT; i++)
	{
		this->m_texture[i].loadFromFile(this->m_imgName[i]);
	}
	this->m_font.loadFromFile("C:/Windows/Fonts/Tahoma.ttf");
}

Rescources::~Rescources()
{
}

Rescources& Rescources::getResource()
{
	static Rescources resource;
	return resource;
}

sf::Font* Rescources::getFont()
{
	return &m_font;
}

sf::Texture* Rescources::getTexture(int obj)
{
	return &m_texture[obj];
}
