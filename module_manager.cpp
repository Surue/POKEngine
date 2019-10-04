#include "module_manager.h"

#include "test_system.h"
#include "singleton.h"

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
	Singleton::Get()->Update();
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
