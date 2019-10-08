#include "test_system.h"

#include "Log.h"
#include "engine.h"
#include "time.h"

namespace poke
{
TestSystem::TestSystem(ModuleManager* moduleManager) : Module(moduleManager)
{
	moduleManager->updateCallback.AddCallback([this]() {return this->Update(); });
	moduleManager->initCallback.AddCallback([this]() {return this->Init(); });
	moduleManager->updatePhysicCallback.AddCallback([this]() {return this->PhysicUpdate(); });
	moduleManager->renderCallback.AddCallback([this]() {return this->Render(); });

	moduleManager->updateCallback.RemoveCallback([this]() {return this->Update(); });
}

TestSystem::~TestSystem() { }

void TestSystem::Init()
{
	log::Log("TestSytem : Init");
}

void TestSystem::Update()
{
	log::Log("TestSytem : Update  |||||||||||||||");
	std::cout << Time::Get().deltaTime.count();
}

void TestSystem::PhysicUpdate()
{
	log::Log("TestSytem : PhysicUpdate ===============");
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
