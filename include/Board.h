#pragma once

#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>
#include "GameObject.h"

class Board
{
private:
	std::vector<std::vector<GameObject>> m_baord;

public:
	Board();
	~Board() = default;
	
	//init level
	void getLevel(const int);

	//print
	void printLevel() const;
};