#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include "system.h"

namespace poke
{
class TestSystem : public System
{
public:
	TestSystem();
	~TestSystem();

	void Init() override;
	void Update() override;
	void PhysicUpdate() override;
	void Destroy() override;
};
}
#endif //TEST_SYSTEM_H
