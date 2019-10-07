#pragma once


#include <thread>

#include "module_manager.h"
#include <vector>


namespace poke
{
/**
 * \brief Main class operating game
 */
class Engine
{
public:
	Engine();
	static Engine& Get();
	~Engine() = default;

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
	void ShutDown();

	/**
	 * \brief Assure that the engine and all cores modules are destroy correctly
	 */
	void Destroy();

	//Getters
	ModuleManager& GetModuleManager();
private:
	
	std::vector<std::thread> mainThread_;
	std::vector<std::thread> drawThread_;
	bool isRunning_{};

	ModuleManager moduleManager_;
};
} //poke
