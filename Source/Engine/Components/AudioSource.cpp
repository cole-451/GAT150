#include "AudioSource.h"
#include "Audio/AudioClip.h"
#include "Engine.h"
namespace parabellum {
	FACTORY_REGISTER(AudioSource)

	void parabellum::AudioSource::Update(float dt)
	{
		//
	}

	void AudioSource::Play()
	{
		auto audioClip = Resources().Get<AudioClip>(clipName, getEngine().getAudioSys());
		if (audioClip) {
			getEngine().getAudioSys().playSound(*audioClip);
		}
	}

	void AudioSource::Read(const json::value_t& value)
	{
		JSON_READ(value, clipName);
	}

}
