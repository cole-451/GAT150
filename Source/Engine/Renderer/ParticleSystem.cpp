#include "ParticleSystem.h"
#include "../Renderer/Renderer.h"

namespace parabellum {
	bool ParticleSystem::initialize(int poolSize) {
		m_particles.resize(poolSize);

		return true;
	}

	void ParticleSystem::GTFO() {

	}
	void ParticleSystem::Update(float dt) {
		for (auto& particle : m_particles) {
			if (particle.active) {
				particle.lifespan -= dt;
				particle.active = (particle.lifespan > 0);
				particle.position += particle.velocity;
			}
		}
	}

	void ParticleSystem::Draw(class Renderer& renderer) {
		for (auto& particle : m_particles) {
			if (particle.active) {
				renderer.setColor(particle.color.r, particle.color.g, particle.color.b);
		}
		}
	}


	void ParticleSystem::addParticle(const Particle particle)
	{
		Particle* particleptr = getFreeParticle();
		if (particleptr) {
			particleptr->active = true;

		}
	}
	Particle* ParticleSystem::getFreeParticle()
	{

		return nullptr;
	}
}