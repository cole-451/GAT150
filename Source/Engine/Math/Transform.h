#pragma once
#include "Vector2.h"

struct Transform {
	vec2 position;
	float rotation;
	float scale;

	Transform() = default;
	Transform(const vec2& position, float rotation = 0, float scale = 1):
		position{position}, // another way of this.position = position
		rotation{rotation},
		scale{scale}
	{ }
};