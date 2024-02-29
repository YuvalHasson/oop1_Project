#pragma once

#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Rescources
{
private:
	std::string m_imgName[OBJ_AMOUNT] = {
		"Mouse.png", "Cat.png", "Cheese.png",
		"Door.png", "Key.png", "Present.png", "Wall.png",
		"Background.png", "Menu.png", "Button.png", "Help.png",
		"Heart.png", "Scoreboard.png", "Clock.png", "Logo.png",
		"GameOver.png", "Winner.png"
	};
	sf::Texture m_texture[OBJ_AMOUNT];
	sf::Image m_icon;
	sf::Font m_font;

public:
	Rescources();
	~Rescources();
	static Rescources& getResource();

	//get
	sf::Texture* getTexture(int);
	sf::Image* getIcon();
	sf::Font* getFont();
};
