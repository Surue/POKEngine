#pragma once

#include "module_manager.h"

namespace poke
{
/**
 * \brief Main class operating game
 */
class Engine
{
public:	
	Engine();
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
	void ShutDown();

	/**
	 * \brief Assure that the engine and all cores modules are destroy correctly
	 */
	void Destroy();
private:
	bool isRunning_;

	ModuleManager systemContainer_;
};
} //poke
