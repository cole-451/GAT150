#pragma once
#include <variant>

namespace parabellum {
	struct Event {
		using id_t = std::string;
		using data_t = std::variant<int, bool, std::string, vec2, vec3>;
		id_t id;
		data_t data;

		Event(const id_t& id, data_t data):
			id{id},
			data{data}
		{ }
		
	};
}