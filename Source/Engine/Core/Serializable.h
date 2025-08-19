#pragma once
#include "json.h"

namespace parabellum { // interface. we are making a list of requirements for anything on the json
	class Serializable {
	public:
		virtual ~Serializable() = default;

		virtual void Read(const json::value_t& value) = 0;
	};
}