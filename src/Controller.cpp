#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(WindowWidth, windowHeight), "Cat & Mouse", sf::Style::Close | sf::Style::Titlebar),
	m_level(1), m_lives(3), m_points(0)
{
	this->m_window.setFramerateLimit(60);
}

Controller::~Controller()
{
}

void Controller::run()
{
	while (this->m_window.isOpen())
	{
		this->m_window.clear(sf::Color(221, 221, 221));
		this->m_window.draw(initBackground());
		m_mainMenu.drawMainMenu(&m_window);

		for (auto event = sf::Event{}; this->m_window.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				this->m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					if (this->m_gameState == GAME_STATE::HELP)
					{
						this->m_gameState = GAME_STATE::MAIN_MENU;
					}
					else
					{
						this->m_window.close();
					}
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (this->m_gameState == GAME_STATE::MAIN_MENU)
				{
					this->m_gameState = m_mainMenu.buttonPressed(&m_window, event.mouseButton);
					
					if (this->m_gameState == GAME_STATE::EXIT)
					{
						this->m_window.close();
					}
					else if (this->m_gameState == GAME_STATE::NEW_GAME)
					{
						//TODO:: insert music
					}
				}
				break;
			default:
				break;
			}
		}
		//draw
		//m_board.draw(&m_window);
		//m_board.initClock();

		this->m_window.display();
	}
}

sf::Sprite Controller::initBackground()
{
	sf::Sprite background;
	background.setTexture(*Rescources::getResource().getTexture(TEXTURE::background));
	return background;
}

