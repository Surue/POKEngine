#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#include "test_system.h"

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
	 * \brief Part of the programme that draw every thing on the screen
	 */
	void Render();
	/**
	 * \brief Called at the end of the programme to destroy 
	 */
	void Destroy();

private:
	TestSystem testSystem_;
};
} //poke
#endif //MODULE_MANAGER_H