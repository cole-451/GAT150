#include "EnginePCH.h"
#include "Core/StringHelper.h"
#include "Event/Observer.h"

namespace parabellum {
	void EventManager::AddObserver(const Event::id_t id, IObserver& observer)
	{
		m_observers[toLower(id)].push_back(&observer);
	}


	void EventManager::RemoveObserver(IObserver& observer)
	{
		IObserver* obsptr = &observer;

		for (auto& eventtype : m_observers) {
			auto& observers = eventtype.second; //get list of observers for event

			//remove observers from this certain event type
			std::erase_if(observers, [obsptr](auto observer) {
				return (observer == obsptr);
			});
		}

	}

	void EventManager::Notify(const Event& event)
	{ // find observers of event
		auto it = m_observers.find(toLower(event.id));
		if (it != m_observers.end()) {
			auto& observers = it->second;
			for (auto observer : observers) {
				observer->OnNotify(event);
			}
		}
		else {
			Logger::Warning("couldn't find event {}", event.id);
		}
	}

}
