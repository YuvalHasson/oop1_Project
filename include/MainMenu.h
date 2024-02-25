#pragma once

#include <SFML/Graphics.hpp>
#include "Utilities.h"
#include "Resources.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class MainMenu
{
private:
	sf::RectangleShape m_newGameBtn, m_helpBtn, m_exitBtn, m_mainBg, m_helpPage;
	sf::Text m_newGameTxt, m_helpText, m_exitText;
public:
	MainMenu();

	void drawMainMenu(sf::RenderWindow* window);
	void drawHelp(sf::RenderWindow* window);
	int buttonPressed(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event);
};
