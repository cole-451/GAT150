#pragma once
#include "chrono"
namespace parabellum {
	class Time
	{
	private:
		using clock = std::chrono::high_resolution_clock;

	public:
		Time() {
			start_time = clock::now();
			frame_time = clock::now();
		}

		void Tick();

		void Reset() {
			start_time = clock::now();
		}

		float getTime() const {
			return m_time;
		}
		float getDeltaTime() const {
			return delta_time;
		}

	private:
		clock::time_point start_time;
		clock::time_point frame_time;
		float m_time = 0;
		float delta_time = 0;
	};
}