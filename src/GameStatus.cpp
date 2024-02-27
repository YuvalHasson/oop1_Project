#include "GameStatus.h"

GameStatus::GameStatus()
{
	this->m_gameLevel.setFont(*Rescources::getResource().getFont());
	this->m_gameLevel.setString("Level: " + std::to_string(1));
	this->m_gameLevel.setStyle(sf::Text::Bold);
	this->m_gameLevel.setPosition(sf::Vector2f(20.f, 5.f));

	this->m_heart.setTexture(Rescources::getResource().getTexture(TEXTURE::heart));
	this->m_heart.setPosition(160.f, 5.f);
	this->m_heart.setSize(sf::Vector2f(35.f, 35.f));
	this->m_lives.setFont(*Rescources::getResource().getFont());
	this->m_lives.setString(": " + std::to_string(3));
	this->m_lives.setStyle(sf::Text::Bold);
	this->m_lives.setPosition(sf::Vector2f(190.f, 5.f));

	this->m_key.setTexture(Rescources::getResource().getTexture(TEXTURE::key));
	this->m_key.setPosition(250.f, 5.f);
	this->m_key.setSize(sf::Vector2f(35.f, 35.f));
	this->m_keys.setFont(*Rescources::getResource().getFont());
	this->m_keys.setString(": " + std::to_string(0));
	this->m_keys.setStyle(sf::Text::Bold);
	this->m_keys.setPosition(sf::Vector2f(280.f, 5.f));

	this->m_score.setTexture(Rescources::getResource().getTexture(TEXTURE::score));
	this->m_score.setPosition(370.f, 0.f);
	this->m_score.setSize(sf::Vector2f(65.f, 45.f));
	this->m_points.setFont(*Rescources::getResource().getFont());
	this->m_points.setString(std::to_string(0));
	this->m_points.setStyle(sf::Text::Bold);
	this->m_points.setPosition(sf::Vector2f(380.f, 5.f));

	this->m_clock.setTexture(Rescources::getResource().getTexture(TEXTURE::clock));
	this->m_clock.setPosition(760.f, 5.f);
	this->m_clock.setSize(sf::Vector2f(35.f, 35.f));
	this->m_timer.setFont(*Rescources::getResource().getFont());
	this->m_timer.setString(": --");
	this->m_timer.setStyle(sf::Text::Bold);
	this->m_timer.setPosition(sf::Vector2f(800.f, 5.f));
}

void GameStatus::draw(sf::RenderWindow* window) const
{
	window->draw(this->m_heart);
	window->draw(this->m_key);
	window->draw(this->m_score);
	window->draw(this->m_clock);
	window->draw(this->m_keys);
	window->draw(this->m_lives);
	window->draw(this->m_points);
	window->draw(this->m_gameLevel);
	window->draw(this->m_timer);
}

void GameStatus::setLives(int lives)
{
	this->m_lives.setString(": " + std::to_string(lives));
}

void GameStatus::setKeys(int keys)
{
	this->m_keys.setString(": " + std::to_string(keys));
}

void GameStatus::setPoints(int points)
{
	this->m_points.setString(std::to_string(points));
}

void GameStatus::setGameLevel(int gameLevel)
{
	this->m_gameLevel.setString("Level: " + std::to_string(gameLevel));
}

void GameStatus::setTimer(int time)
{
	this->m_timer.setString(": " + std::to_string(time));
}
