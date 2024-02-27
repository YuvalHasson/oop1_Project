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
#include "PresentLife.h"
#include "PresentCat.h"
#include "PresentTime.h"
#include "PresentFreeze.h"
#include "Cat.h"


class Board
{
private:
	std::vector<std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;

	sf::Clock m_clock, m_movementClock;

	int m_rows, m_cols, m_timeLimit;

	GameStatus m_status;

	int m_level, m_lives, m_points, m_cheese, m_presents, m_doors;

	sf::Clock m_clockFreeze;
	sf::Time m_freezeTime;
	

public:
	Board();
	~Board() = default;

	void draw(sf::RenderWindow*);
	
	//init level
	bool getLevel(const int);
	void initVector(char, Vertex);
	void handleAndMove();
		
	void updateStatus(MovingObject*);
	void resetLocations();
	void resetClock();
	void checkCatWall(MovingObject*);

	//get
	int getTime() const;
	int getLives() const;
	int getPoints() const;

	//set
	void setLives(int);
	void setPoints(int);
	void setLevel(int);
	void setCurrentObj();
	void setNextObj();
	void setToRemove(MovingObject*);
	void setToFreeze();
};