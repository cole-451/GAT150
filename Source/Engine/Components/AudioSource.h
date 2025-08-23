#pragma once
#include "Framework/Component.h"

namespace parabellum {
	class AudioSource : public Component {
	public:
		std::string clipName;

	public:
		CLASS_PROTOTYPE(AudioSource)


		// Inherited via Component
		void Update(float dt) override;

		void Play();

		void Read(const json::value_t& value) override;


	};
}