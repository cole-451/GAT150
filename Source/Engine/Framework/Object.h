#pragma once
#include <string>
#include "Core/Serializable.h"

namespace parabellum {
	class Object : public Serializable {
	public:
		std::string name;
		bool active{ true };
	public:
		Object() = default;
		virtual ~Object() = default; // must be virtual because it will destroy the parent, not anyone part OF Object


		// Inherited via Serializable
		void Read(const json::value_t& value) override;

	};
}