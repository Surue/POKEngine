#ifndef SYSTEM_CONTAINER_H
#define SYSTEM_CONTAINER_H
#include <vector>
#include <memory>

#include "system.h"
#include "test_system.h"

namespace poke
{
class SystemContainer
{
public:
	SystemContainer();
	~SystemContainer();

	void Init();
	void Update();
	void PhysicUpdate();
	void Render();
	void Destroy();

private:
	TestSystem testSystem_;
};
}
#endif //SYSTEM_CONTAINER_H