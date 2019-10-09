#pragma once


#include <thread>

#include "module_manager.h"
#include <vector>
#include "callbacks_container.h"

namespace poke
{
/**
 * \brief Main class operating app
 */
class Engine
{
public:
	static Engine& Get();
	Engine(Engine&) = delete;
	Engine(Engine*) = delete;
	~Engine();

	/**
	 * \brief Called once to initialize the engine and cores module
	 */
	void Init();
	/**
	 * \brief Called to run the engine after the initialization
	 */
	void Run();
	/**
	 * \brief Shut down the engine and force to stop the main loop
	 */
	void Stop();
	/**
	 * \brief Assure that the engine and all cores modules are destroy correctly
	 */
	void Destroy();

	//Getters
	ModuleManager& GetModuleManager();
	
	CallbackContainer& GetCallbackContainer();

private:
	//constructor private to assure a singleton
	Engine();

	//Threads
	std::vector<std::thread> mainThread_;
	std::vector<std::thread> drawThread_;

	//Running values
	bool isRunning_{};

	std::unique_ptr<ModuleManager> moduleManager_;

	CallbackContainer callbackContainer_;
};
} //namespace poke
