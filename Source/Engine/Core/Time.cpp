#include "Time.h"

void parabellum::Time::Tick()
{
	clock::time_point now = clock::now();
	m_time = std::chrono::duration<float>(now - start_time).count();
	delta_time = std::chrono::duration<float>(now - frame_time).count();
	frame_time = now;

}
