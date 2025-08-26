#include "EnginePCH.h"
#include "Core/StringHelper.h"

namespace parabellum {
	void EventManager::AddObserver(const Event::id_t id, IObserver& observer)
	{
		m_observers[toLower(id)].push_back(&observer);
	}


	void EventManager::RemoveObserver(IObserver& observer)
	{
		IObserver* obsptr = &observer;

		for (auto& eventtype : m_observers) {
			auto observers = eventtype.second; //get list of observers for event
			std::erase_if(observers, [obsptr](auto observer) {
				return (observer == obsptr);
			});
		}

	}

	void EventManager::Notify(const Event& event)
	{

	}

}
