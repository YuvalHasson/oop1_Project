#pragma once

#include "Utilities.h"
#include <SFML/Audio.hpp>

class SoundResource
{
private:
	std::string m_soundNames[SOUND_AMOUNT] = {
		"KeysPickup.ogg", "OpenDoor.ogg", "Eating.ogg", "Scream.ogg",
		"GiftPickup.ogg", "ItemRespawn.ogg", "GameComplete.ogg",
		"GameWin.ogg", "GameOver.ogg", "CatFreeze.ogg",
		"FreezeEnd.ogg", "AddLife.ogg", "AddTime.ogg"
	};

	std::string m_backgroundNames[BACK_SOUND_AMNT] = {
		"Monkeys.ogg", "Menu.ogg"
	};

	sf::Music m_backgroundMusic[BACK_SOUND_AMNT];
	sf::SoundBuffer m_buffers[SOUND_AMOUNT];;
	sf::Sound m_sounds[SOUND_AMOUNT];

public:
	SoundResource();
	~SoundResource();

	static SoundResource& getSound();

	void playSound(int);
	void playBackground(int);
	void stopBackground(int);
};