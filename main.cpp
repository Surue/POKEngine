#include "engine.h"

#include <iostream>
#include <thread>

#include "windows.h" 

int main()
{
	poke::Engine engine;

	/*for(int i = 0; i < 100; i++)
	{
		std::cout << "i = " << i << "\n";
		Sleep((1.0f * 1000) / 60.0f);
		system("cls");
	}*/

	engine.Init();

	engine.Run();

	system("pause");
	return EXIT_SUCCESS;
}
