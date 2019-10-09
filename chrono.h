#pragma once
#include <chrono>

namespace poke
{
/**
 * \brief Use to compute time in nano seconds. Mainly for short code for computing short amount of time and doing some optimization
 */
class Chrono
{
public:
	/**
	 * \brief Create and start the chronometer immediately
	 */
	Chrono();
	~Chrono() = default;

	/**
	 * \brief Reset starting time to now
	 */
	void Restart();

	/**
	 * \brief Return time elapsed in nano seconds
	 */
	double GetTime() const;

private:
	std::chrono::steady_clock::time_point startTime_;
};
} //namespace poke
