#pragma once
#include "Resources/Resource.h"
#include "Audio/AudioSys.h"

namespace parabellum {
	class AudioClip : public Resource {
	public:
		AudioClip() = default;
		~AudioClip();
		bool Load(const std::string& filename, audiosys& audiosystem);
	private:
		friend class audiosys;
		FMOD::Sound* m_sound{ nullptr };
	};
}