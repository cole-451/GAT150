#pragma once
#include "json.h"

namespace parabellum { // interface. we are making a list of requirements for anything on the json
	class ISerializable {
	public:
		virtual ~ISerializable() = default;

		virtual void Read(const json::value_t& value) = 0;
	};
}