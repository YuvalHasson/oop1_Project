#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Board
{
private:
	std::vector<std::string> m_baord;

public:
	Board();
	~Board() = default;
	
	//init level
	void getLevel(const int);

	//get
	int getBoardSize() const;
	std::vector<std::string> getBoard() const;

	//print
	void printLevel() const;
};