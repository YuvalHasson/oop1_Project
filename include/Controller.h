#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Utilities.h"
#include "Board.h"

class Controller
{
private:
	sf::RenderWindow m_window;

	sf::Texture m_texture[OBJ_AMOUNT];

	Board m_board;
	
public:
	Controller();
	~Controller();

	void run();
};
