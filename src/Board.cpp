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

	for (auto line = std::string(); std::getline(lvl, line);)//line == col
	{			
		this->m_baord.push_back(line);
	}
}

int Board::getBoardSize() const
{
	return this->m_baord.size();
}

std::vector<std::string> Board::getBoard() const
{
	return this->m_baord;
}

void Board::printLevel() const
{
	for (size_t i = 0; i < this->m_baord.size(); i++)
	{
		for (size_t j = 0; j < this->m_baord[i].size(); j++)
		{
			std::cout << this->m_baord[i][j];
		}
		std::cout << "\n";
	}
}
