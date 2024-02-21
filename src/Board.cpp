#include "Board.h"

Board::Board(int level, int lives, int points)
	:m_lives(lives), m_points(points), m_keys(0)
{
	this->getLevel(level);
	
}

void Board::draw(sf::RenderWindow* window)
{
	for (size_t i = 0; i < this->m_staticObjects.size(); i++)
	{
		window->draw(this->m_staticObjects[i]->getSprite());
	}
	for (size_t i = 0; i < this->m_movingObjects.size(); i++)
	{
		window->draw(this->m_movingObjects[i]->getSprite());
	}
}

void Board::getLevel(const int level)
{
	std::string currLvl = "Level" + std::to_string(level) + ".txt";

	auto lvl = std::ifstream(currLvl);
	if (!lvl)
	{
		exit(EXIT_FAILURE);
	}
	this->m_movingObjects.clear();
	this->m_staticObjects.clear();
	

	lvl >> m_rows >> m_cols;

	size_t row = 0;
	for (auto line = std::string(); std::getline(lvl, line); row++)//line == col
	{			
		for (size_t col = 0; col < line.size(); col++)
		{
			initVector(line[col], Vertex(col, row));
		}
	}
}

void Board::initVector(char c, Vertex loc)
{
	float size = (windowHeight - loc.m_y) / std::max(m_rows, m_cols);
	if (c != ' ')
	{
		
		switch (c)
		{
		case '%': //mouse
			this->m_movingObjects.push_back(std::make_unique<Mouse>(loc, Size(size, size), m_lives, m_keys, MouseSpeed));
			break;
		case '^': //Cat
			this->m_movingObjects.push_back(std::make_unique<Cat>(loc, Size(size, size), CatSpeed));
			break;
		case '#': //Wall
			this->m_staticObjects.push_back(std::make_unique<Wall>(loc, Size(size, size)));
			break;
		case '*': //Cheese
			this->m_staticObjects.push_back(std::make_unique<Cheese>(loc, Size(size, size)));
			break;
		case 'D': //Door
			this->m_staticObjects.push_back(std::make_unique<Door>(loc, Size(size, size)));
			break;
		case 'F': //Key
			this->m_staticObjects.push_back(std::make_unique<Key>(loc, Size(size, size)));
			break;
		case '$': //Present
			this->m_staticObjects.push_back(std::make_unique<Present>(loc, Size(size, size)));
			break;
		default:
			break;
		}
	}
}

void Board::initClock()
{
	auto deltaTime = this->m_clock.restart();
	
	for (size_t i = 0; i < this->m_movingObjects.size(); i++)
	{
		this->m_movingObjects[i]->move(deltaTime);

		for (size_t j = 0; j < this->m_movingObjects.size(); j++)
		{
			if (this->m_movingObjects[i]->collidesWith(*this->m_movingObjects[j])) {
				this->m_movingObjects[i]->handleCollision(*this->m_movingObjects[j]);
			}
		}

		for (size_t j = 0; j < this->m_staticObjects.size(); j++)
		{
			if (this->m_movingObjects[i]->collidesWith(*this->m_staticObjects[j])) {
				this->m_movingObjects[i]->handleCollision(*this->m_staticObjects[j]);
				this->m_staticObjects[j]->handleCollision(*this->m_movingObjects[i]);
			}
		}
	}
}

int Board::getLives() const
{
	return this->m_lives;
}

int Board::getPoints() const
{
	return this->m_points;
}
