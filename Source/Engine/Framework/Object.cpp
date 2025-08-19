#include "EnginePCH.h"
namespace parabellum {

void parabellum::Object::Read(const json::value_t& value)
{
	JSON_READ(value, name);
	JSON_READ(value, active);
}
}
