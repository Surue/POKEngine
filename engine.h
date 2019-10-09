#pragma once

#include <vector>
#include <thread>

#include "module_container.h"
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
	~Engine();

	//Create true singleton
	Engine(Engine&) = delete;
	Engine(Engine&&) = delete;
	Engine& operator = (Engine);
	Engine& operator = (Engine&&) noexcept;

	/**
	 * \brief Called once to initialize the engine and cores module. Everything before this points expect the engine doesn't exist
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
	/**
	 * \brief Get module manager
	 */
	ModuleContainer& GetModuleManager();
	/**
	 * \brief Get callback container 
	 */
	CallbackContainer& GetCallbackContainer();

private:
	//constructor private to assure a singleton
	Engine();

	//Threads
	std::vector<std::thread> mainThread_;
	std::vector<std::thread> drawThread_;

	//Running values
	bool isRunning_{};

	std::unique_ptr<ModuleContainer> moduleManager_;

	CallbackContainer callbackContainer_;
};
} //namespace poke
