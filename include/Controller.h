#pragma once

#include <SFML/Graphics.hpp>

#include "Utilities.h"
#include "MainMenu.h"
#include "Board.h"
#include "Mouse.h"

class Controller
{
private:
	sf::RenderWindow m_window;

	sf::Texture m_texture[OBJ_AMOUNT];

	Board m_board;
	MainMenu m_mainMenu;

	int m_level;
	int m_points;
	int m_lives;
	
public:
	Controller();
	~Controller();

	void run();
	sf::Sprite initBackground();

};
