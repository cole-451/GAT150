#pragma once
#include <rapidjson/document.h>
#include <string>

namespace parabellum::json {
	
	bool Load(const std::string& filename, rapidjson::Document& document);

	bool Read(const rapidjson::Value& value, const std::string& name, int& data);

	

}