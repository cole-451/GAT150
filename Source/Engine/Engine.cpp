#include "Engine.h"

#include "Renderer/Renderer.h"
#include "Audio/AudioSys.h"
#include "Input/InputSystem.h"


namespace parabellum {
bool Engine::initialize() {
	m_renderer = std::make_unique<Renderer>();
	m_renderer->initialize();
	m_renderer->createWindow("parabellum engine", 1280, 1024, false);

	m_inputsys = std::make_unique<InputSystem>();
	m_inputsys->initialize();

	m_audio = std::make_unique<audiosys>();
	m_audio->init();

	m_ps = std::make_unique<ParticleSystem>();
	m_ps->initialize();

	
	return true;
}

void Engine::GTFO() {
	Resources().Clear();
	Factory::Instance().FuckAllOfYou();
	EventManager::Instance().RemoveAll();
	m_audio->GTFO();
	m_inputsys->GTFO();
	m_renderer->GTFO();
	m_ps->GTFO();
}

void Engine::Draw()
{
	m_ps->Draw(*m_renderer);

}

void Engine::update() {
	m_time.Tick();
	m_inputsys->Update(m_time.getDeltaTime()); // maybe get delta time as something???
	m_audio->update();
	m_ps->Update(m_time.getDeltaTime());
}




}