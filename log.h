#ifndef LOG_H
#define LOG_H
#include <string>
#include <iostream>

namespace poke
{
namespace log
{
/**
 * \brief log a given text in the console
 * \param s 
 */
static void Log(const std::string& s)
{
	std::cout << s << "\n";
}

/**
 * \brief Clear the console
 */
static void Clear()
{
	system("cls");
}
} //namespace log
} //namespace poke

#endif // LOG_H
