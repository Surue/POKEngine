#pragma once

#include "test_system.h"
#include "callback.h"

namespace poke
{
/**
 * \brief function managing all engine's module. It's called by the engine from the run function
 */
class ModuleManager
{
public:
	ModuleManager();
	~ModuleManager() = default;

	static ModuleManager& Get();
	
	TestSystem& GetTestSystem();
private:
	TestSystem testSystem_;
};
} //poke
