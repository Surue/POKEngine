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
	~Time() = default;

	static Time& Get()
	{
		static Time instance;
		return instance;
	}

	/**
	 * \brief Time to complete last frame in milliseconds
	 */
	std::chrono::duration<double, std::milli> deltaTime{};

	float GetTime() const;
private:
	Time() = default;
	
	std::chrono::steady_clock::time_point startFrame_;
	std::chrono::steady_clock::time_point endFrame_;

	std::chrono::steady_clock::time_point startTime_;
	
	/**
	 * \brief Called a the start of the frame. Used to compute deltaTime. Used to compute deltaTime
	 */
	void StartFrame();

	/**
	 * \brief Called a the end of a frame then compute delta time. Used to compute deltaTime
	 */
	void EndFrame();

	/**
	 * \brief Can be called during a frame to get the time from the start of the frame to now
	 * \return the time elapsed in milliseconds
	 */
	float GetFrameElapsedTime() const;

	void StartRecordingTime();

};
} //namespace poke
