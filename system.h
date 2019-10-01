#ifndef SYSTEM_H
#define SYSTEM_H

namespace poke
{
class System
{
public:
	System();
	~System();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void PhysicUpdate() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;

	void Test();

private:
};
}
#endif //SYSTEM_H
