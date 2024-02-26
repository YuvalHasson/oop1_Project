#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(WindowWidth, windowHeight), "Cat & Mouse", sf::Style::Close | sf::Style::Titlebar),
	m_level(0), m_lives(3), m_points(0)
{
	this->m_window.setFramerateLimit(60);
	SoundResource::getSound().playBackground(BACKGROUND::menu);
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
					SoundResource::getSound().stopBackground(BACKGROUND::menu);
					SoundResource::getSound().playBackground(BACKGROUND::background);
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
	
		if (Cheese::getCheese() == 0)
		{
			this->m_level += 1;
			if (!this->m_board.getLevel(this->m_level))
			{
				this->returnToMenu();
			}
			else
			{
				if (this->m_level > 1)
				{
					this->m_board.resetClock();
					this->m_points = this->m_board.getPoints();
				}
			}
		}

		if (this->m_board.getTime() <= 0)
		{
			this->m_board.resetClock();
			this->m_board.setLives(--this->m_lives);
			this->m_board.setPoints(this->m_points);
			this->m_board.getLevel(this->m_level);
		}

		if (this->m_board.getLives() == 0)
		{
			this->returnToMenu();
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
		this->m_board.handleAndMove();
		break;
	default:
		break;
	}

	this->m_window.display();
}

void Controller::returnToMenu()
{
	SoundResource::getSound().stopBackground(BACKGROUND::background);
	SoundResource::getSound().playBackground(BACKGROUND::menu);
	this->m_board.resetClock();
	this->m_gameState = GAME_STATE::MAIN_MENU;
	this->m_level = 1;
	this->m_board.setLives(3);
	this->m_board.setPoints(0);
	this->m_board.getLevel(this->m_level);
}

sf::Sprite Controller::initBackground()
{
	sf::Sprite background;
	background.setTexture(*Rescources::getResource().getTexture(TEXTURE::background));
	return background;
}

