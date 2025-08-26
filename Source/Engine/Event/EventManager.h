#pragma once
#include "Core/Singleton.h"
#include "Event/Event.h"
#include "Event/Observer.h"
#include <map>
#include <list>
namespace parabellum {
	class EventManager : public Singleton<EventManager> {
	public:
		void AddObserver(const Event::id_t id, IObserver& observer);
		void RemoveObserver(IObserver& observer);

		void Notify(const Event& event);

		std::map<Event::id_t, std::list<IObserver*>> m_observers;

		Actor* actor{ nullptr };
	};
}