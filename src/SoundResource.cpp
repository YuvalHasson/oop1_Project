
#include "SoundResources.h"

SoundResource::SoundResource()
{
	this->m_backgroundMusic.openFromFile("Monkeys.ogg");

	for (size_t i = 0; i < SOUND_AMOUNT; i++)
	{
		this->m_buffers[i].loadFromFile(this->m_soundNames[i]);
	}
	for (size_t i = 0; i < SOUND_AMOUNT; i++)
	{
		this->m_sounds[i].setBuffer(this->m_buffers[i]);
	}
}

SoundResource::~SoundResource()
{
}

SoundResource& SoundResource::getSound()
{
	static SoundResource sound;
	return sound;
}

void SoundResource::playSound(int sound)
{
	this->m_sounds[sound].play();
}

void SoundResource::playBackgroud()
{
	this->m_backgroundMusic.play();
}
