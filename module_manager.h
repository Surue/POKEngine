#pragma once
#include <functional>

#include "test_system.h"
#include <iostream>
#include <vector>
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
	~ModuleManager();

	void Init();
	/**
	 * \brief Called every frame for game logic
	 */
	void Update();
	/**
	 * \brief Called every frame at a constant frame rate for the physic
	 */
	void PhysicUpdate();
	/**
	 * \brief Part of the program that draw every thing on the screen
	 */
	void Render();
	/**
	 * \brief Called at the end of the program to destroy 
	 */
	void Destroy();

	TestSystem& GetTestSystem()
	{
		return testSystem_;
	}

	Callback<VoidCallback> initCallback;
	Callback<VoidCallback> updateCallback;
	Callback<VoidCallback> updatePhysicCallback;
	Callback<VoidCallback> renderCallback;
private:
	TestSystem testSystem_;
	TestSystem testSystem2_;

};
} //poke
