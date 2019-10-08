#pragma once
#include <chrono>

namespace poke
{
class Engine;

class Time
{
public:
	friend class Engine;
	Time(Time& t) = delete;

	static Time& Get()
	{
		static Time instance;
		return instance;
	}

	std::chrono::duration<double, std::milli> deltaTime{};

private:
	Time() = default;
	
	std::chrono::steady_clock::time_point startFrame_;
	std::chrono::steady_clock::time_point endFrame_;

	void StartFrame()
	{
		startFrame_ = std::chrono::high_resolution_clock::now();
	}

	void EndFrame()
	{
		endFrame_ = std::chrono::high_resolution_clock::now();
		deltaTime = endFrame_ - startFrame_;
	}
};
} //namespace poke
