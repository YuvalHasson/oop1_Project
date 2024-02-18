#include "Controller.h"

Controller::Controller()
	:m_window(sf::VideoMode(WindowWidth, windowHeight), "Cat & Mouse", sf::Style::Default), m_board(), m_level(1)
{
	this->m_window.setFramerateLimit(60);
	this->m_board.printLevel();
}

Controller::~Controller()
{
}

void Controller::run()
{
	while (this->m_window.isOpen())
	{
		this->m_window.clear();
		
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


		this->m_window.display();
	}
}

