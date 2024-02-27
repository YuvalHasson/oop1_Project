#include "Board.h"

Board::Board()
	:m_lives(3), m_points(0), m_level(1), m_cheese(),
	m_presents(), m_cols(), m_rows(), m_timeLimit()
{
	srand(time(NULL));
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

bool Board::getLevel(const int level)
{
	std::string currLvl = "Level" + std::to_string(level) + ".txt";

	auto lvl = std::ifstream(currLvl);
	if (!lvl)
	{
		return false;
	}
	this->m_movingObjects.clear();
	this->m_staticObjects.clear();
	

	lvl >> this->m_rows >> this->m_cols >> this->m_timeLimit;

	size_t row = 0;
	for (auto line = std::string(); std::getline(lvl, line); row++)//line == col
	{			
		for (size_t col = 0; col < line.size(); col++)
		{
			initVector(line[col], Vertex((float)col, (float)row));
		}
	}
	return true;
}

void Board::initVector(char c, Vertex loc)
{
	int randomPresent;

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
			
			randomPresent  = rand() % 4;

			if (randomPresent == 0)
			{
				this->m_staticObjects.push_back(std::make_unique<PresentLife>(loc, Size(size_x, size_y)));
			}	
			else if (randomPresent == 1)
			{
				this->m_staticObjects.push_back(std::make_unique<PresentCat>(loc, Size(size_x, size_y)));
			}
			else if (randomPresent == 2)
			{
				this->m_staticObjects.push_back(std::make_unique<PresentTime>(loc, Size(size_x, size_y)));
			}
			else if (randomPresent == 3)
			{
				this->m_staticObjects.push_back(std::make_unique<PresentFreeze>(loc, Size(size_x, size_y)));
			}
			break;
		default:
			break;
		}
	}
}

void Board::handleAndMove()
{
	auto deltaTime = this->m_movementClock.restart();
	
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
				if (dynamic_cast<Cat*>(&*m_movingObjects[i]))
				{
					dynamic_cast<Cat*>(this->m_movingObjects[i].get())->updateMetWall();
				}
			}
		}
		this->setToRemove(this->m_movingObjects[i].get());
		this->updateStatus(this->m_movingObjects[i].get());
	}

	this->setToFreeze();
	this->resetLocations();

	this->m_cheese = Cheese::getCheese();
	this->m_presents = Present::getPresents();
	
	std::erase_if(this->m_staticObjects, [](const auto& StaticObejects) { return StaticObejects->isEaten(); });
	std::erase_if(this->m_movingObjects, [](const auto& movingObjects) { return movingObjects->isRemove(); });

	--this->m_cheese;
	--this->m_presents;

	MovingObject::resetLocation();
}

void Board::updateStatus(MovingObject* ptr)
{
	Mouse* mouse = dynamic_cast<Mouse*>(ptr);
	if (mouse)
	{
		this->m_status.setKeys(mouse->getKeys());
		this->m_lives = mouse->getLives();

		if (PresentTime::getPresentTime())
		{
			this->m_timeLimit += ADDTIME;
			PresentTime::setPresentTime(false);
		}

		if (this->m_presents == Present::getPresents())
		{
			this->m_points += PRESENTPOINTS;
		}

		if (this->m_cheese == Cheese::getCheese())
		{
			this->m_points += CHEESEPOINTS;
		}
	}
	this->m_status.setLives(this->m_lives);
	this->m_status.setPoints(this->m_points);
	this->m_status.setGameLevel(this->m_level);
	this->m_status.setTimer(this->getTime());
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

void Board::resetClock()
{
	this->m_clock.restart();
}

int Board::getTime() const
{
	return this->m_timeLimit - this->m_clock.getElapsedTime().asSeconds();
}

int Board::getLives() const
{
	return this->m_lives;
}

int Board::getPoints() const
{
	return this->m_points;
}

void Board::setLives(int lives)
{
	this->m_lives = lives;
}

void Board::setPoints(int points)
{
	this->m_points = points;
}

void Board::setLevel(int level)
{
	this->m_level = level;
}

void Board::setToRemove(MovingObject* ptr)
{
	if (PresentCat::getPresetnTaken())
	{
		Cat* cat = dynamic_cast<Cat*>(ptr);
		if (cat)
		{
			cat->remove();
			PresentCat::setPresentTaken(false);
		}
	}
}

void Board::setToFreeze()
{
	if (PresentFreeze::getPresentFreeze())
	{
		m_clockFreeze.restart();
		Cat::setFreeze(true);

		PresentFreeze::setPresentFreeze(false);
	}
	m_freezeTime = m_clockFreeze.getElapsedTime();
	if (Cat::getFreeze())
	{
		if (m_freezeTime.asSeconds() >= FREEZETIME)
		{
			SoundResource::getSound().playSound(SOUND::unfreeze);
			Cat::setFreeze(false);
		}
	}
}
