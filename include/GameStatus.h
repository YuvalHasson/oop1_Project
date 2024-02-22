#pragma once

#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Resources.h"

class GameStatus
{
private:
	sf::Text m_timer;
	sf::Text m_gameLevel;
	sf::Text m_lives;
	sf::Text m_keys;
	sf::Text m_points;

public:
	GameStatus();

	void draw(sf::RenderWindow* window);

	//set
	/*void setLives(int);
	void setKeys(int);
	void setPoints(int);
	void setGameLevel(int);*/

	//get
	//int getLives() const;
	//int getKeys() const;
	//int getPoints() const;
	//int getGameLevel() const;
};