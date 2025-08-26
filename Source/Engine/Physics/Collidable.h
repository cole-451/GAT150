#pragma once

namespace parabellum {
	class ICollidable {
	public:
		virtual ~ICollidable() = default;

		virtual void OnCollision(Actor* other) = 0;
	};
}