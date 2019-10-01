#include "system_container.h"

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
}
