#include "singleton.h"

namespace poke
{
Singleton::Singleton() = default;

Singleton* Singleton::Get()
{
	static Singleton instance;

	return &instance;
}
} //namespace poke
