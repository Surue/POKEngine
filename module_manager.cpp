#include "module_manager.h"

#include "test_system.h"
#include "engine.h"

namespace poke
{
ModuleManager::ModuleManager(){ }

ModuleManager& ModuleManager::Get()
{
	return Engine::Get().GetModuleManager();
}

TestSystem& ModuleManager::GetTestSystem()
{
	return testSystem_;
}
} //namespace poke
