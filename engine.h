#ifndef ENGINE_H
#define ENGINE_H
#include "Log.h"

namespace poke
{
class Engine
{
public:
	Engine();
	~Engine();

	void Init()
	{
		log::Log("Engine Start()");

		//Create basics systems
		
	}

	void Run()
	{
		int maxIteration = 1000;
		while(isRunning_)
		{
			log::Log("Get Inputs");

			log::Log("PhysicUpdate");

			log::Log("Update");

			log::Log("Render");

			maxIteration--;
			if(maxIteration <= 0)
			{
				isRunning_ = false;
			}

			log::Clear();
		}
	}

	void ShutDown()
	{
		
	}

	void Destroy()
	{
		
	}
private:
	bool isRunning_;
};
}
#endif //ENGINE_H
