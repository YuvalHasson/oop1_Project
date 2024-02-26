#pragma once

#include "Utilities.h"
#include <SFML/Audio.hpp>

class SoundResource
{
private:
	std::string m_soundNames[SOUND_AMOUNT] = {
		"KeysPickup.ogg", "OpenDoor.ogg", "Eating.ogg", "Scream.ogg",
		"GiftPickup.ogg"
	};

	sf::Music m_backgroundMusic;
	sf::SoundBuffer m_buffers[SOUND_AMOUNT];;
	sf::Sound m_sounds[SOUND_AMOUNT];

public:
	SoundResource();
	~SoundResource();

	static SoundResource& getSound();

	void playSound(int);
	void playBackgroud();
};