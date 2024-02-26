#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(WindowWidth, windowHeight), "Cat & Mouse", sf::Style::Close | sf::Style::Titlebar),
	m_level(0), m_lives(3), m_points(0)
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
		this->updateLevel();
		this->pollEvent();
		this->menu();
	}
}

void Controller::pollEvent()
{
	this->m_window.clear();

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
					SoundResource::getSound().playBackgroud();
				}
			}
			break;
		default:
			break;
		}
	}
}

void Controller::updateLevel()
{
	if (this->m_gameState == GAME_STATE::NEW_GAME)
	{
		//TODO: check cheese amount
		if (Cheese::getCheese() == 0)
		{
			this->m_level += 1;
			this->m_board.getLevel(this->m_level);
		}
	}
}

void Controller::menu()
{
	switch (this->m_gameState)
	{
	case GAME_STATE::MAIN_MENU:
		this->m_mainMenu.drawMainMenu(&this->m_window);
		break;
	case GAME_STATE::HELP:
		this->m_mainMenu.drawHelp(&this->m_window);
		break;
	case GAME_STATE::NEW_GAME:
		this->m_window.draw(initBackground());
		this->m_board.draw(&m_window);
		this->m_board.initClock();
		break;
	default:
		break;
	}

	this->m_window.display();
}

sf::Sprite Controller::initBackground()
{
	sf::Sprite background;
	background.setTexture(*Rescources::getResource().getTexture(TEXTURE::background));
	return background;
}

