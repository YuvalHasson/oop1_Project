#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>

#include "GameStatus.h"

#include "Mouse.h"
#include "Wall.h"
#include "Cheese.h"
#include "Door.h"
#include "Key.h"
#include "Present.h"
#include "Cat.h"


class Board
{
private:
	
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

	sf::Clock m_clock;

	int m_rows, m_cols;

	GameStatus m_status;

	int m_level;
	int m_lives;
	int m_points;
	int m_cheese;

public:
	Board();
	~Board() = default;

	void draw(sf::RenderWindow*);
	
	//init level
	void getLevel(const int);
	void initVector(char, Vertex);
	void initClock();

	
	void updateStatus(MovingObject*);
	void resetLocations();
};