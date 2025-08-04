#pragma once
#include <string>

namespace parabellum {
	inline std::string toLower(const std::string& string) {
		std::string result = string;
		for (char& c : result) {
			c = std::tolower(c);
		}
		return result;
	}
	inline std::string toHigher(const std::string& string) {
		std::string result = string;
		for (char& c : result) {
			c = std::toupper(c);
		}
		return result;
	}
}