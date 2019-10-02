#include "module_manager.h"

#include "test_system.h"

namespace poke
{
ModuleManager::ModuleManager()
{
	
}


ModuleManager::~ModuleManager() { }

void ModuleManager::Init()
{
	testSystem_.Init();
}

void ModuleManager::Update()
{
	testSystem_.Update();
}

void ModuleManager::PhysicUpdate()
{
	testSystem_.PhysicUpdate();
}

void ModuleManager::Render()
{
	testSystem_.Render();
}

void ModuleManager::Destroy()
{
	testSystem_.Destroy();
}
} //poke
