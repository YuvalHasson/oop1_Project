#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(WindowWidth, windowHeight), "Cat & Mouse", sf::Style::Default),
	m_level(1), m_lives(3), m_points(0), m_board(m_level = 1, m_lives, m_points)
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
		}
		//draw
		m_board.draw(&m_window);
		m_board.initClock();

		this->m_window.display();
	}
}

