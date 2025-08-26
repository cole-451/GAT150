#pragma once
#include "Core/Time.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSys.h"
#include "Input/InputSystem.h"
#include "Renderer/ParticleSystem.h"
#include "Core/Singleton.h"
#include "Resources/ResourceManager.h"
#include "Physics/Physics.h"

#include <memory>

namespace parabellum {
	class Engine: public Singleton<Engine> {
	public:
		
		bool initialize();
		void update();
		void GTFO();

		void Draw();

		Renderer& getRenderer() {
			return *m_renderer;
		}

		InputSystem& getInputSys() {
			return *m_inputsys;
		}

		audiosys& getAudioSys() {
			return *m_audio;
		}

		Time& getTime() {
			return m_time;
		}

		ParticleSystem& getPS() {
			return *m_ps;
		}

		Physics& GetPhysics() { return *m_physics; }

	private:
		friend class Singleton<Engine>;
		Engine() = default;

	private:
		Time m_time;
		std::unique_ptr<Renderer> m_renderer;

		std::unique_ptr<class InputSystem> m_inputsys;

		std::unique_ptr<audiosys> m_audio;

		std::unique_ptr<ParticleSystem> m_ps;

		std::unique_ptr<Physics> m_physics;


		
	};
	// ground zero of the 238 errors
	inline Engine& getEngine() { return Engine::Instance(); }

}