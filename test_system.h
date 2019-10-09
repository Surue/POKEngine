#pragma once
#include "Module.h"
#include "timer.h"

namespace poke
{
class TestSystem : public Module
{
public:
	TestSystem();
	~TestSystem() = default;

	void Init() override;
	void Update() override;
	void PhysicUpdate() override;
	void Render() override;
	void Destroy() override;
private:
	int testValue_ = 0;

	Timer timer_ = Timer(10, true);
};
}
