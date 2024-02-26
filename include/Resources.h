#pragma once

#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Rescources
{
private:
	std::string m_imgName[OBJ_AMOUNT] = {
		"Mouse.png", "Cat.png", "Cheese.png",
		"Door.png", "Key.png", "Present.png", "Wall.png",
		"Background.png", "Menu.png", "Button.png", "Help.png"
	};
	sf::Texture m_texture[OBJ_AMOUNT];
	sf::Font m_font;

public:
	Rescources();
	~Rescources();
	static Rescources& getResource();

	//get
	sf::Texture* getTexture(int);
	sf::Font* getFont();
};
