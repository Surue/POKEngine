#include "time.h"

void poke::Time::StartFrame()
{
	startFrame_ = std::chrono::high_resolution_clock::now();
}

void poke::Time::EndFrame()
{
	endFrame_ = std::chrono::high_resolution_clock::now();
	deltaTime = endFrame_ - startFrame_;
}

float poke::Time::GetFrameElapsedTime() const
{
	const std::chrono::duration<double, std::milli> elapsedTime = std::chrono::high_resolution_clock::now() -
		startFrame_;
	return elapsedTime.count();
}

void poke::Time::StartRecordingTime()
{
	startTime_ = std::chrono::high_resolution_clock::now();
}

float poke::Time::GetTime() const
{
	const std::chrono::duration<double> elapsedTime = std::chrono::high_resolution_clock::now() -
		startTime_;
	return elapsedTime.count();
}
