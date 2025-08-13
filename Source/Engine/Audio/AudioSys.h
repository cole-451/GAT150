#pragma once
#include <fmod.hpp>
#include <string>
#include <map>


namespace parabellum {
	class audiosys {
	public:
		audiosys() = default;

		bool init();

		void GTFO();

		void update();

		bool addSound(const std::string& filename, const std::string& name = "");

		bool playSound(const std::string& name);

		bool playSound(class AudioClip& clip);

	private:
		friend class AudioClip;
		FMOD::System* system = nullptr;
		static bool checkFMODResult(FMOD_RESULT result);
		std::map<std::string, FMOD::Sound*> soundmap;

	};
}
