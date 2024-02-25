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
			default:
				break;
			}
			int num = m_mainMenu.buttonPressed(&m_window, event.mouseButton);
			if (num == 2)
			{
				m_mainMenu.drawHelp(&m_window);
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

