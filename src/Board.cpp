#include "Board.h"

Board::Board()
	:m_lives(3), m_points(0), m_level(1), m_cheese(),
	m_cols(), m_rows()
{
}

void Board::draw(sf::RenderWindow* window)
{
	m_status.draw(window);
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
			initVector(line[col], Vertex((float)col, (float)row));
		}
	}

}

void Board::initVector(char c, Vertex loc)
{
	float size_x = (windowHeight - loc.m_x) / std::max(m_rows, m_cols);
	float size_y = (WindowWidth - loc.m_y) / std::max(m_rows, m_cols);

	if (c != ' ')
	{
		switch (c)
		{
		case '%': //mouse
			this->m_movingObjects.push_back(std::make_unique<Mouse>(loc, Size(size_x, size_y), m_lives, MouseSpeed));
			break;
		case '^': //Cat
			this->m_movingObjects.push_back(std::make_unique<Cat>(loc, Size(size_x, size_y), CatSpeed));
			break;
		case '#': //Wall
			this->m_staticObjects.push_back(std::make_unique<Wall>(loc, Size(size_x, size_y)));
			break;
		case '*': //Cheese
			this->m_staticObjects.push_back(std::make_unique<Cheese>(loc, Size(size_x, size_y)));
			break;
		case 'D': //Door
			this->m_staticObjects.push_back(std::make_unique<Door>(loc, Size(size_x, size_y)));
			break;
		case 'F': //Key
			this->m_staticObjects.push_back(std::make_unique<Key>(loc, Size(size_x, size_y)));
			break;
		case '$': //Present
			this->m_staticObjects.push_back(std::make_unique<Present>(loc, Size(size_x, size_y)));
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
			if (this->m_movingObjects[i]->collidesWith(*this->m_movingObjects[j]))
			{
				this->m_movingObjects[i]->handleCollision(*this->m_movingObjects[j]);
			}
		}

		for (size_t j = 0; j < this->m_staticObjects.size(); j++)
		{
			if (this->m_movingObjects[i]->collidesWith(*this->m_staticObjects[j]))
			{
				this->m_movingObjects[i]->handleCollision(*this->m_staticObjects[j]);
				this->m_staticObjects[j]->handleCollision(*this->m_movingObjects[i]);
			}
		}
		this->updateStatus(this->m_movingObjects[i].get());
	}

	this->resetLocations();

	this->m_cheese = Cheese::getCheese();

	std::erase_if(this->m_staticObjects, [](const auto& StaticObejects) { return StaticObejects->isEaten(); });
	
	--this->m_cheese;
	MovingObject::resetLocation();
}

void Board::updateStatus(MovingObject* ptr)
{
	Mouse* mouse = dynamic_cast<Mouse*>(ptr);
	if (mouse)
	{
		this->m_status.setKeys(mouse->getKeys());
		this->m_lives = mouse->getLives();

		if (this->m_cheese == Cheese::getCheese())
		{
			this->m_points += 5;
		}
	}
	this->m_status.setLives(this->m_lives);
	this->m_status.setPoints(this->m_points);
	this->m_status.setGameLevel(this->m_level);
}

void Board::resetLocations()
{
	for (size_t i = 0; i < this->m_movingObjects.size(); i++)
	{
		if (MovingObject::isResetLocation())
		{
			this->m_movingObjects[i]->setInitialLocation();
		}
	}
}
