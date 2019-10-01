#include "test_system.h"
#include "Log.h"

namespace poke
{
TestSystem::TestSystem() { }


TestSystem::~TestSystem() { }

void TestSystem::Init()
{
	log::Log("TestSytem : Init");
}

void TestSystem::Update()
{
	log::Log("TestSytem : Update");
}

void TestSystem::PhysicUpdate()
{
	log::Log("TestSytem : PhysicUpdate");
}

void TestSystem::Render()
{
	log::Log("TestSytem : Render");
}

void TestSystem::Destroy()
{
	log::Log("TestSytem : Destroy");
}
}
