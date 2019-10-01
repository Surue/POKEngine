#ifndef ENGINE_H
#define ENGINE_H
#include "Log.h"
#include "system_container.h"

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
		systemContainer_.Init();
	}

	void Run()
	{
		log::Log("Engine Run()");
		
		int iteration = 0;
		const int maxIteration = 1000;
		isRunning_ = true;
		
		while(isRunning_)
		{
			log::Log("i = " + std::to_string(iteration));
			
			log::Log("Get Inputs");

			log::Log("PhysicUpdate");
			systemContainer_.PhysicUpdate();

			log::Log("Update");
			systemContainer_.Update();

			log::Log("Render");
			systemContainer_.Render();

			iteration++;
			if(iteration >= maxIteration)
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

	SystemContainer systemContainer_;
};
}
#endif //ENGINE_H
