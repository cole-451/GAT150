#pragma once
#include "Vector2.h"
#include "Core/Serializable.h"

namespace parabellum {

struct Transform : public parabellum::Serializable {
	vec2 position;
	float rotation;
	float scale;

	Transform() = default;
	Transform(const vec2& position, float rotation = 0, float scale = 1):
		position{position}, // another way of this.position = position
		rotation{rotation},
		scale{scale}
	{ }

	void Read(const parabellum::json::value_t& value);
};
}