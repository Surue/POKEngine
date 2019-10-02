#include "engine.h"
#include "Log.h"

namespace poke
{
Engine::Engine()
{
	log::Log("Engine - Construct");
}

Engine::~Engine() { }

void Engine::Init()
{
	log::Log("Engine Start()");

	//Create basics systems
	systemContainer_.Init();
}

void Engine::Run()
{
	log::Log("Engine Run()");

	int iteration = 0; //TODO enlever ça
	const int maxIteration = 1000;

	isRunning_ = true;

	while (isRunning_)
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
		if (iteration >= maxIteration)
		{
			isRunning_ = false;
		}

		log::Clear();
	}

	Destroy();
}

void Engine::ShutDown()
{
	isRunning_ = false;
}

void Engine::Destroy() { }
}
