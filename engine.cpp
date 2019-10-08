#include "engine.h"

#include <thread>

#include "Log.h"
#include "windows.h" 
#include "time.h"
#include "timer.h"

namespace poke
{
Engine::Engine()
{
	log::Log("Engine - Construct");
	Time::Get().StartRecordingTime();
}

Engine& Engine::Get()
{
	static Engine instance;
	return instance;
}

Engine::~Engine() {}

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

	isRunning_ = true;

	Timer timer = Timer(100);
	
	while (!timer.IsOver())
	{
		Time::Get().StartFrame();
		log::Log("i = " + std::to_string(iteration));

		log::Log("Get Inputs");

		log::Log("PhysicUpdate");
		mainThread_.emplace_back(&ModuleManager::PhysicUpdate, moduleManager_);

		log::Log("Update");
		mainThread_.emplace_back(&ModuleManager::Update, moduleManager_);

		log::Log("Render");
		drawThread_.emplace_back(&ModuleManager::Render, moduleManager_);

		iteration++;

		//Wait end of frame
		for (auto& th : mainThread_) th.join();
		for (auto& th : drawThread_) th.join();

		mainThread_.clear();
		drawThread_.clear();

		const auto elapsedTime = Time::Get().GetFrameElapsedTime();
		if(elapsedTime < 1.0 * 1000.0 / 60.0)
			Sleep(1.0 * 1000.0 / 60.0 - elapsedTime);
		
		Time::Get().EndFrame();
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
