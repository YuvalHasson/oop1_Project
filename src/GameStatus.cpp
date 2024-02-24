#include "GameStatus.h"

GameStatus::GameStatus()
{
	m_keys.setFont(*Rescources::getResource().getFont());
	m_lives.setFont(*Rescources::getResource().getFont());
	m_points.setFont(*Rescources::getResource().getFont());
	m_timer.setFont(*Rescources::getResource().getFont());
	m_gameLevel.setFont(*Rescources::getResource().getFont());
	
	m_lives.setString("Lives: " + std::to_string(3));
	m_lives.setStyle(sf::Text::Bold);
	m_lives.setPosition(sf::Vector2f(30.f, 60.f));

	m_keys.setString("Key: " + std::to_string(0));
	m_keys.setStyle(sf::Text::Bold);
	m_keys.setPosition(sf::Vector2f(150.f, 60.f));

	m_points.setString("Points: " + std::to_string(0));
	m_points.setStyle(sf::Text::Bold);
	m_points.setPosition(sf::Vector2f(260.f, 60.f));


}

void GameStatus::draw(sf::RenderWindow* window)
{
	window->draw(this->m_keys);
	window->draw(this->m_lives);
	window->draw(this->m_points);
	//window->draw(this->m_RgameLevel);

}

void GameStatus::setLives(int lives)
{
	this->m_lives.setString("Lives: " + std::to_string(lives));
}

void GameStatus::setKeys(int keys)
{
	this->m_keys.setString("Keys: " + std::to_string(keys));
}

void GameStatus::setPoints(int points)
{
	this->m_points.setString("Points: " + std::to_string(points));
}

//void GameStatus::setGameLevel(int gameLevel)
//{
//	this->m_gameLevel = gameLevel;
//}

//
//int GameStatus::getLives() const
//{
//	return this->m_lives;
//}
//
//int GameStatus::getKeys() const
//{
//	return this->m_keys;
//}
//
//int GameStatus::getPoints() const
//{
//	return this->m_points;
//}
//
//int GameStatus::getGameLevel() const
//{
//	return this->m_gameLevel;
//}
