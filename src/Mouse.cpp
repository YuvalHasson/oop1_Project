#include "Mouse.h"

Mouse::Mouse(Vertex loc, Size size, int lives, int speed)
	:MovingObject(loc, size, speed), m_lives(lives), m_keys(0)
{
	this->setSprite(TEXTURE::mouse);
	this->setLocation(this->getSprite().getPosition());
	this->setStarterLocation(this->getLocation());
}

void Mouse::move(sf::Time deltaTime)
{
	this->setLastLocation(this->getLocation());

	auto s = this->getSize().m_x / 380;

	this->getSprite().setOrigin(sf::Vector2f(this->getSprite().getTexture()->getSize() / 2u));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->directionUp();
		this->getSprite().setRotation(90.f);
		this->getSprite().setScale(-s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->directionDown();
		this->getSprite().setRotation(270.f);
		this->getSprite().setScale(-s, -s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->directionRight();
		this->getSprite().setRotation(0.f);
		this->getSprite().setScale(s, s);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->directionLeft();
		this->getSprite().setRotation(180.f);
		this->getSprite().setScale(s, -s);
	}
	this->getSprite().move(this->getDirection() * this->getSpeed() * deltaTime.asSeconds());

	this->setMouseLocation(this->getLocation());

	this->setLocation(this->getSprite().getPosition());
	
	this->resetDirection();
}

void Mouse::handleCollision(GameObject& other)
{
	return other.handleCollision(*this);
}

void Mouse::handleCollision(Cat&)
{
	SoundResource::getSound().playSound(SOUND::scream);
	--this->m_lives;
	this->setResetLocation();
}

void Mouse::handleCollision(Cheese&)
{
	SoundResource::getSound().playSound(SOUND::eating);
}

void Mouse::handleCollision(Wall&)
{
	this->setLocation(this->getLastLocation());
	this->getSprite().setPosition(this->getLastLocation());
}

void Mouse::handleCollision(Key&)
{
	SoundResource::getSound().playSound(SOUND::key_pickup);
	++this->m_keys;
}

void Mouse::handleCollision(Door&)
{
	if (this->m_keys > 0)
	{
		SoundResource::getSound().playSound(SOUND::door_open);
		--this->m_keys;
	}
	else
	{
		this->setLocation(this->getLastLocation());
		this->getSprite().setPosition(this->getLastLocation());
	}
}

void Mouse::handleCollision(Present&)
{
	SoundResource::getSound().playSound(SOUND::present);
}

int Mouse::getKeys() const
{
	return this->m_keys;
}

int Mouse::getLives() const
{
	return this->m_lives;
}

void Mouse::addLife()
{
	this->m_lives++;
}

