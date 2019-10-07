#include "engine.h"

#include <thread>

#include "windows.h" 

int main()
{

	/*for(int i = 0; i < 100; i++)
	{
		std::cout << "i = " << i << "\n";
		Sleep((1.0f * 1000) / 60.0f);
		system("cls");
	}*/

	poke::Engine& engine = poke::Engine::Get();

	engine.Init();
	engine.Run();

	system("pause");
	return EXIT_SUCCESS;
}
