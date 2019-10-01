#include "system_container.h"

#include "system.h"
#include "Log.h"
#include "test_system.h"

namespace poke
{
SystemContainer::SystemContainer()
{
	
}


SystemContainer::~SystemContainer() { }

void SystemContainer::Init()
{
	testSystem_.Init();
}

void SystemContainer::Update()
{
	testSystem_.Update();
}

void SystemContainer::PhysicUpdate()
{
	testSystem_.PhysicUpdate();
}

void SystemContainer::Render()
{
	testSystem_.Render();
}

void SystemContainer::Destroy()
{
	testSystem_.Destroy();
}

void SystemContainer::AddSystem(System *system)
{
	systems_.push_back(std::make_unique<System>(*system));
}
}
