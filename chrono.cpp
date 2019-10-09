#include "chrono.h"

namespace poke
{
Chrono::Chrono()
{
	startTime_ = std::chrono::high_resolution_clock::now();
}

void Chrono::Restart()
{
	startTime_ = std::chrono::high_resolution_clock::now();
}

double Chrono::GetTime() const
{
	const std::chrono::duration<double, std::nano> elapsedTime = std::chrono::high_resolution_clock::now() -
		startTime_;
	return elapsedTime.count();
}
}
