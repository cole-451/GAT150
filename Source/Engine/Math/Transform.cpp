#include "EnginePCH.h"

namespace parabellum {
void Transform::Read(const parabellum::json::value_t& value)
{
	JSON_READ(value, position);
	JSON_READ(value, rotation);
	JSON_READ(value, scale);
}

}
