#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(WindowWidth, windowHeight), "Mouse & Cat", sf::Style::Close | sf::Style::Titlebar),
	m_level(0), m_lives(3), m_points(0)
{
	this->m_window.setFramerateLimit(60);
	this->m_window.setIcon(Rescources::getResource().getIcon()->getSize().x, Rescources::getResource().getIcon()->getSize().y,
		Rescources::getResource().getIcon()->getPixelsPtr());
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
					this->returnToMenu();
					//this->m_window.close();
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
	this->m_mainMenu.changecolerWhilePointing(&this->m_window);
	if (this->m_gameState == GAME_STATE::NEW_GAME)
	{
		if (Cheese::getCheese() == 0)
		{
			this->m_board.resetClock();
			this->m_level += 1;
			if (!this->m_board.getLevel(this->m_level))
			{
				SoundResource::getSound().playSound(SOUND::win);
				this->returnToMenu();
			}
			else
			{
				if (this->m_level > 1)
				{
					SoundResource::getSound().playSound(SOUND::level_up);
					this->m_board.resetClock();
					this->m_board.setLevel(this->m_level);
					this->m_points = this->m_board.getPoints() + CHEESEPOINTS + LVLCMPLT;
				}
			}
		}

		if (this->m_board.getTime() <= 0)
		{
			SoundResource::getSound().playSound(SOUND::time_over);
			this->m_board.resetClock();
			this->m_lives = this->m_board.getLives();
			this->m_board.setLives(--this->m_lives);
			this->m_board.setPoints(this->m_points);
			this->m_board.getLevel(this->m_level);
		}

		if (this->m_board.getLives() <= 0)
		{
			SoundResource::getSound().playSound(SOUND::lose);
			this->screen(TEXTURE::background);
			
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
	this->m_board.setLevel(m_level);
	this->m_board.setLives(3);
	this->m_board.setTime();
	this->m_board.setPoints(0);
	this->m_board.getLevel(this->m_level);
}

void Controller::screen(int screen)
{
	sf::Sprite s;
	s.setTexture(*Rescources::getResource().getTexture(screen));
	s.setPosition(0.f, 0.f);
	m_window.draw(s);

	while (true)
	{
		m_window.clear();
		m_window.draw(s);
		m_window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}
	}
}

sf::Sprite Controller::initBackground()
{
	sf::Sprite background;
	background.setTexture(*Rescources::getResource().getTexture(TEXTURE::background));
	return background;
}

