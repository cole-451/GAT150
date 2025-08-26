#pragma once

namespace parabellum {
	class IObserver {
		virtual ~IObserver() = default;

		virtual void OnNotify(const Event& event) = 0;
	};
}