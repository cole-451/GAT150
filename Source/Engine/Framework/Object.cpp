#include "EnginePCH.h"
namespace parabellum {

void parabellum::Object::Read(const json::value_t& value)
{
	// look at how you are supposed to read strings and bools from your json.cpp file.
	JSON_READ(value, name);
	JSON_READ(value, active);
}
}
