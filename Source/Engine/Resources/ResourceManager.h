#pragma once
#include "Core/StringHelper.h"
#include "Resource.h"
#include "Core/Singleton.h"
#include "Core/Logger.h"
#include<map>
#include <string>
#include <memory>
#include <iostream>

namespace parabellum {
	class ResourceManager : public Singleton<ResourceManager> {
	public:

		void Clear() { m_resources.clear(); }
		template <typename T, typename ... Args>
			requires std::derived_from<T, Resource>

		res_t<T> Get(const std::string& name, Args&& ... args);

		template <typename T, typename ... Args>
			requires std::derived_from<T, Resource>

		res_t<T> GetWithID(const std::string& name, const std::string& id, Args&& ... args);


	private:
		ResourceManager() = default; // allows us to only have one instance of ResourceManager existing

	private:
		std::map<std::string, res_t<Resource>> m_resources;
		friend class Singleton<ResourceManager>;
	};
	template <typename T, typename ... Args>
		requires std::derived_from<T, Resource>

	inline res_t<T> ResourceManager::Get(const std::string& name, Args&& ... args) {
		std::string key = toLower(name);
		auto iter = m_resources.find(key);
		if (iter != m_resources.end()) {
			auto base = iter->second;
			auto resource = std::dynamic_pointer_cast<T>(base);
			//check for success
			if (!resource) {
				Logger::Error("Resource type mismatch");
				return res_t<T>();
			}
			return resource;
		}
		//load resource
		res_t<T> resource = std::make_shared<T>(); // is there something wrong here?
		if (resource->Load(key, std::forward<Args>(args)...) == false) {
			Logger::Error("Could not load resource.");
			return res_t<T>();
		}
		//add resource to manager
		m_resources[key] = resource;
		return resource;
		//return GetWithID<T>(name, name, std::forward<Args>(args)...));
	}

	template<typename T, typename ...Args>
		requires std::derived_from<T, Resource>

	inline res_t<T> ResourceManager::GetWithID(const std::string& name, const std::string& id, Args && ...args)
	{
		std::string key = toLower(id);
		auto iter = m_resources.find(key);
		if (iter != m_resources.end()) {
			auto base = iter->second;
			auto resource = std::dynamic_pointer_cast<T>(base);
			//check for success
			if (!resource) {
				Logger::Error("Resource type mismatch");
				return res_t<T>();
			}
			return resource;
		}
		//load resource
		res_t<T> resource = std::make_shared<T>();
		if (resource->Load(name, std::forward<Args>(args)...) == false) {
			Logger::Error("Could not load resource.");
			return res_t<T>();
		}
		//add resource to manager
		m_resources[key] = resource;
		return resource;
	}




	inline ResourceManager& Resources() { return ResourceManager::Instance(); }

}