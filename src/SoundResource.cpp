
#include "SoundResources.h"

SoundResource::SoundResource()
{
	for (size_t i = 0; i < BACK_SOUND_AMNT; i++)
	{
		this->m_backgroundMusic[i].openFromFile(this->m_backgroundNames[i]);
	}
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

void SoundResource::playBackground(int sound)
{
	this->m_backgroundMusic[sound].setLoop(true);
	this->m_backgroundMusic[sound].play();
}

void SoundResource::stopBackground(int sound)
{
	this->m_backgroundMusic[sound].stop();
}
