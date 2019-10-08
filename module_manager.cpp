#include "module_manager.h"

#include "test_system.h"

namespace poke
{
ModuleManager::ModuleManager(): testSystem_(this) { }


ModuleManager::~ModuleManager() { }

void ModuleManager::Init()
{
	initCallback.RegisterCallbacks();
}

void ModuleManager::Update()
{
	updateCallback.RegisterCallbacks();
}

void ModuleManager::PhysicUpdate()
{
	updatePhysicCallback.RegisterCallbacks();
}

void ModuleManager::Render()
{
	renderCallback.RegisterCallbacks();
}

void ModuleManager::Destroy()
{
	testSystem_.Destroy();
}
} //poke
