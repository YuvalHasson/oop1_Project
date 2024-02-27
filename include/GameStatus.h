#pragma once

#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Resources.h"

class GameStatus
{
private:
	sf::RectangleShape m_heart;
	sf::RectangleShape m_clock;
	sf::RectangleShape m_key;
	sf::RectangleShape m_score;

	sf::Text m_timer;
	sf::Text m_gameLevel;
	sf::Text m_lives;
	sf::Text m_keys;
	sf::Text m_points;

public:
	GameStatus();

	void draw(sf::RenderWindow* window) const;

	//set
	void setLives(int);
	void setKeys(int);
	void setPoints(int);
	void setGameLevel(int);
	void setTimer(int);
};