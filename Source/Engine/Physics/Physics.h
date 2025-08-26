#pragma once
#include <box2d/box2d.h>
#include <memory>

namespace parabellum {
	//watch the video tonight (8/26) to fix up certain box2D stuff.

	class Physics {
	public:
		Physics() = default;

		bool Initialize();
		void Shutdown();

		void Update(float dt);

	private:
		b2WorldId m_worldId;
	};
}