#include "Board.h"

Board::Board()
{
	this->getLevel(1);
}

void Board::getLevel(const int level)
{
	std::string currLvl = "Level" + std::to_string(level) + ".txt";

	auto lvl = std::ifstream(currLvl);
	if (!lvl)
	{
		exit(EXIT_FAILURE);
	}
	this->m_baord.clear();

	size_t row = 0;
	for (auto line = std::string(); std::getline(lvl, line); row++)
	{			
		std::vector<GameObject> objectLine;
		for (size_t col = 0; col < line.size(); col++)//col
		{	
			auto tmpObject = GameObject();
			tmpObject.setChar(line[col]);
			tmpObject.setLocation(row, col);
			objectLine.push_back(tmpObject);
		}
		this->m_baord.push_back(objectLine);
	}
}

void Board::printLevel() const
{
	for (size_t i = 0; i < this->m_baord.size(); i++)
	{
		for (size_t j = 0; j < this->m_baord[i].size(); j++)
		{
			std::cout << this->m_baord[i][j].getChar();
		}
		std::cout << "\n";
	}
}
