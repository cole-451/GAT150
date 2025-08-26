#include "Observer.h"

namespace parabellum {
	IObserver::~IObserver() {
		OBSERVER_REMOVE_SELF;
		//EventManager::Instance().RemoveObserver(*this);
	}
	// when they die, they will remove themselves from the event
}