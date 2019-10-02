#pragma once
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
