#include "engine.h"
#include "Log.h"

namespace poke
{
Engine::Engine()
{
	log::Log("Engine - Construct");
}

Engine& Engine::Get()
{
	static auto instance = std::make_unique<Engine>();
	return *instance;
}

void Engine::Init()
{
	log::Log("Engine Start()");

	//Create basics systems
	moduleManager_.Init();
	log::Log("Engine Start() =========");
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
		mainThread_.emplace_back(&ModuleManager::PhysicUpdate, moduleManager_);

		log::Log("Update");
		mainThread_.emplace_back(&ModuleManager::Update, moduleManager_);

		log::Log("Render");
		drawThread_.emplace_back(&ModuleManager::Render, moduleManager_);

		iteration++;
		if (iteration >= maxIteration)
		{
			isRunning_ = false;
		}

		//Wait end of frame
		for (auto& th : mainThread_) th.join();
		for (auto& th : drawThread_) th.join();

		mainThread_.clear();
		drawThread_.clear();
		log::Clear();
	}

	Destroy();
}

void Engine::ShutDown()
{
	isRunning_ = false;
}

void Engine::Destroy() { }

ModuleManager& Engine::GetModuleManager()
{
	return moduleManager_;
}
}
