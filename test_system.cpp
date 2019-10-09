#include "test_system.h"

#include "Log.h"
#include "engine.h"
#include "time.h"
#include "chrono.h"

namespace poke
{
TestSystem::TestSystem()
{
	Engine::Get().GetCallbackContainer().updateCallback.AddCallback([this]() {return this->Update(); });
	Engine::Get().GetCallbackContainer().initCallback.AddCallback([this]() {return this->Init(); });
	Engine::Get().GetCallbackContainer().updatePhysicCallback.AddCallback([this]() {return this->PhysicUpdate(); });
	Engine::Get().GetCallbackContainer().renderCallback.AddCallback([this]() {return this->Render(); });
	Engine::Get().GetCallbackContainer().destroyCallback.AddCallback([this]() {return this->Destroy(); });
}

void TestSystem::Init()
{
	log::Log("TestSytem : Init");
}

int Fib(const int n)
{
	if(n < 2)
	{
		return n;
	}
	return Fib(n - 1) + Fib(n - 2);
}

int Fib2(const int n)
{
	std::vector<short> numbers;
	numbers.resize(n);
	numbers[0] = 1;
	numbers[1] = 1;

	for(auto i = 2; i < n; i++)
	{
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	}

	return numbers[n - 1];
}

int Fib3(const int n)
{
	int n1 = 0;
	int n2 = 1;

	int newValue = 1;

	for (auto i = 2; i < n; i++)
	{
		n1 = n2;
		n2 = newValue;
		newValue = n2 + n1;
	}

	return newValue;
}

void TestSystem::Update()
{
	log::Log("TestSytem : Update  |||||||||||||||");
	std::cout << "dt   = " << Time::Get().deltaTime.count() << "\n";
	std::cout << "time = " << Time::Get().GetTime() << "\n";
	Chrono chrono = Chrono();
	std::cout << Fib(20) << "\n";
	std::cout << chrono.GetTime() << "\n";
	chrono.Restart();
	std::cout << Fib2(20) << "\n";
	std::cout << chrono.GetTime() << "\n";
	chrono.Restart();
	std::cout << Fib3(20) << "\n";
	std::cout << chrono.GetTime() << "\n";
	chrono.Restart();
	std::cout << chrono.GetTime();
	
	if(timer_.IsOver())
	{
		std::cout << "OVER\n";
	}
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
