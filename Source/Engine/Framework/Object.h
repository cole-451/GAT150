#pragma once
#include <string>

namespace parabellum {
	class Object {
	public:
		std::string name;
		bool active{ true };
	public:
		Object() = default;
		virtual ~Object() = default; // must be virtual because it will destroy the parent, not anyone part OF Object

	};
}