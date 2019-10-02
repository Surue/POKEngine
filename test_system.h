#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include "Module.h"

namespace poke
{
class TestSystem : public Module
{
public:
	TestSystem();
	~TestSystem();

	void Init() override;
	void Update() override;
	void PhysicUpdate() override;
	void Render() override;
	void Destroy() override;
};
}
#endif //TEST_SYSTEM_H
