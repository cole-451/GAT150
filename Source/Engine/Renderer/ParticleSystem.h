#pragma once
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include <vector>

namespace parabellum {
	struct Particle {
		bool active = false;
		vec2 position;
		vec2 velocity;

		vec3 color;
		float lifespan = 1;
	};

	class ParticleSystem {
	public:
		ParticleSystem() = default;

		bool initialize(int poolSize = 100);

		void GTFO();

		void Update(float dt);
		void Draw(class Renderer& renderer);

		void addParticle(const Particle particle);

	private:
		Particle* getFreeParticle();

	private:
		std::vector<Particle> m_particles;
	};
}