#pragma once
#include <string>
#include "Core/Serializable.h"

#define CLASS_PROTOTYPE(classname) 	virtual std::unique_ptr<Object> Clone() { return std::make_unique<classname>(*this); }


namespace parabellum {
	class Object : public Serializable {
	public:
		std::string name;
		bool active{ true };
	public:
		Object() = default;
		virtual ~Object() = default; // must be virtual because it will destroy the parent, not anyone part OF Object

		virtual std::unique_ptr<Object> Clone() = 0;

		// Inherited via Serializable
		void Read(const json::value_t& value) override;

	};
}