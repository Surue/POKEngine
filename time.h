#pragma once
#include <chrono>

namespace poke
{
class Engine;

/**
 * \brief Singleton to access time from anywhere in the engine of the app
 */
class Time
{
public:
	friend class Engine;
	
	Time(Time& t) = delete;
	~Time() = default;

	/**
	 * \brief Get the time singleton
	 */
	static Time& Get();

	/**
	 * \brief Time to complete last frame in milliseconds
	 */
	std::chrono::duration<double, std::milli> deltaTime{};

	/**
	 * \brief Get time since start of the engine
	 * \return 
	 */
	float GetTime() const;
private:
	Time() = default;

	//Frame timer
	std::chrono::steady_clock::time_point startFrame_;
	std::chrono::steady_clock::time_point endFrame_;

	//Global timer
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
	 * \brief Start recording time for the whole game
	 */
	void StartRecordingTime();
	/**
	 * \brief Can be called during a frame to get the time from the start of the frame to now
	 * \return the time elapsed in milliseconds
	 */
	float GetFrameElapsedTime() const;
};
} //namespace poke
