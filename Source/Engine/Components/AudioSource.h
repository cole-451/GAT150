#pragma once
#include "Framework/Component.h"

namespace parabellum {
	class AudioSource : public Component {
	public:
		std::string clipName;

	public:


		// Inherited via Component
		void Update(float dt) override;

		void Play();

	};
}