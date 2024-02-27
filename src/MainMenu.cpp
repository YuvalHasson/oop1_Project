#include "MainMenu.h"

MainMenu::MainMenu()
{
	// set menu space
	m_mainBg.setPosition(0.f, 0.f);
	m_mainBg.setSize(sf::Vector2f(WindowWidth, windowHeight));
	m_mainBg.setTexture(Rescources::getResource().getTexture(TEXTURE::menu));

	// set new game button
	m_newGameBtn.setPosition(320, 210.f);
	m_newGameBtn.setSize(sf::Vector2f(300, 100));
	m_newGameBtn.setTexture(Rescources::getResource().getTexture(TEXTURE::button));
	m_newGameTxt.setFont(*Rescources::getResource().getFont());
	m_newGameTxt.setString("NEW GAME");
	m_newGameTxt.setStyle(sf::Text::Bold);
	m_newGameTxt.setPosition(385, 240.f);

	// set help button
	m_helpBtn.setPosition(320, 320.f);
	m_helpBtn.setSize(sf::Vector2f(300, 100));
	m_helpBtn.setTexture(Rescources::getResource().getTexture(TEXTURE::button));
	m_helpText.setFont(*Rescources::getResource().getFont());
	m_helpText.setString("HELP");
	m_helpText.setStyle(sf::Text::Bold);
	m_helpText.setPosition(435, 350.f);

	// set help window
	m_helpPage.setPosition(0.f, 0.f);
	m_helpPage.setSize(sf::Vector2f(WindowWidth, windowHeight));
	m_helpPage.setTexture(Rescources::getResource().getTexture(TEXTURE::help));

	// set exit button
	m_exitBtn.setPosition(320, 430.f);
	m_exitBtn.setSize(sf::Vector2f(300, 100));
	m_exitBtn.setTexture(Rescources::getResource().getTexture(TEXTURE::button));
	m_exitText.setFont(*Rescources::getResource().getFont());
	m_exitText.setString("EXIT");
	m_exitText.setStyle(sf::Text::Bold);
	m_exitText.setPosition(435, 460.f);
}

void MainMenu::drawMainMenu(sf::RenderWindow* window) const
{
	window->draw(m_mainBg);
	window->draw(m_newGameBtn);
	window->draw(m_newGameTxt);
	window->draw(m_exitBtn);
	window->draw(m_exitText);
	window->draw(m_helpBtn);
	window->draw(m_helpText);
}

void MainMenu::drawHelp(sf::RenderWindow* window) const
{
	window->draw(m_helpPage);
}

void MainMenu::changecolerWhilePointing(sf::RenderWindow* window)
{
	sf::Vector2i mouseLoc = sf::Mouse::getPosition(*window);
	if (m_newGameBtn.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_newGameBtn.setFillColor(sf::Color::Green);
	}
	else
	{
		m_newGameBtn.setFillColor(sf::Color::White);
	}

	if (m_helpBtn.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_helpBtn.setFillColor(sf::Color::Green);
	}
	else
	{
		m_helpBtn.setFillColor(sf::Color::White);
	}

	if (m_exitBtn.getGlobalBounds().contains(mouseLoc.x, mouseLoc.y))
	{
		m_exitBtn.setFillColor(sf::Color::Green);
	}
	else
	{
		m_exitBtn.setFillColor(sf::Color::White);
	}
}

int MainMenu::buttonPressed(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event)
{
	if (m_newGameBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
	{
		return NEW_GAME;
	}
	else if (m_helpBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
	{
		return HELP;
	}
	else if (m_exitBtn.getGlobalBounds().contains(window->mapPixelToCoords({ event.x, event.y })))
	{
		return EXIT;
	}
	return MAIN_MENU;
}
