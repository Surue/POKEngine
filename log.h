#ifndef LOG_H
#define LOG_H
#include <string>
#include <iostream>

namespace poke
{
namespace log {
	static void Log(const std::string& s)
	{
		std::cout << s << "\n";
	}
}
}

	

#endif
