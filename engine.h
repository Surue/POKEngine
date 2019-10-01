#ifndef ENGINE_H
#define ENGINE_H
#include "system_container.h"

namespace poke
{
class Engine
{
public:
	Engine();
	~Engine();

	void Init();

	void Run();

	void ShutDown()
	{
		
	}

	void Destroy()
	{
		
	}
private:
	bool isRunning_;

	SystemContainer systemContainer_;
};
}
#endif //ENGINE_H
