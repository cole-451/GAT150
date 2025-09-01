#pragma once
#include "Vector2.h"
#include "Core/Serializable.h"

namespace parabellum {

struct Transform : public parabellum::ISerializable {
	vec2 position{ 0, 0 };
	float rotation{ 0 };
	float scale{ 1 };

	Transform() = default;
	Transform(const vec2& position, float rotation = 0, float scale = 1):
		position{position}, // another way of this.position = position
		rotation{rotation},
		scale{scale}
	{ }

	void Read(const parabellum::json::value_t& value);
};
}