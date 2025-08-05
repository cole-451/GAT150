#pragma once
#include "Core/StringHelper.h"
#include "Resource.h"
#include<map>
#include <string>
#include <memory>
#include <iostream>

namespace parabellum {
	class ResourceManager {
	public:
		template <typename T, typename ... TArgs>
		res_t<T> Get(const std::string& name, TArgs&& ... args);

	private:
		std::map<std::string, res_t<Resource>> m_resources;
		template <typename T, typename ... TArgs>

		inline res_t<T> ResourceManager::Get(const std::string& name, TArgs&& ... args) {
			//did my fucking compiler turn off?
			std::string key = toLower(name);
			auto iter = m_resources.find(key);
			if (iter != m_resources.end()) {
				auto base = iter->second;
				auto resource = std::dynamic_pointer_cast<T>(base);
				//check for success
				if (!resource) {
					std::cerr << "Resource type mismatch: " << key << std::endl;
					return res_t<T>();
				}
				return resource;
			}
			//load resource
			res_t<T> resource = std::make_shared<T>();
			if (resource->Load(key, std::forward<TArgs>(args)...) == false) {
				std::cerr << "cant load resource:" << key << std::endl;
				return res_t<T>();
			}
			//add resource to manager
			m_resources[key] = resource;
			return resource;
		}
	};

	inline ResourceManager& Resources() {
		static ResourceManager instance;
		return instance;
	}
}