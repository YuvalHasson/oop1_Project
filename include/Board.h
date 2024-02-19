#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <memory>

#include "Resources.h"
#include "Mouse.h"
#include "Wall.h"


class Board
{
private:
	
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

	int m_rows, m_cols;

	int m_lives;
	int m_points;
	int m_keys;

public:
	Board(int, int, int);
	~Board() = default;

	void draw(sf::RenderWindow*);
	
	//init level
	void getLevel(const int);
	void initVector(char, Vertex);

	//get
	int getLives() const;
	int getPoints() const;
};