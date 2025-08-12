#pragma once
#include "Resources/Resource.h"
#include "Audio/AudioSys.h"

namespace parabellum {
	class AudioClip : public Resource {
	public:
		AudioClip() = default;
		~AudioClip() = default;
		bool Load(const std::string& filename, audiosys& audiosystem);
	private:
		FMOD::Sound* m_sound{ nullptr };
	};
}