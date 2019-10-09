#include "Module.h"
#include <iostream>

namespace poke
{
Module::Module()
{
	
}

Module& Module::operator=(Module)
{
	return *this;
}

Module& Module::operator=(Module&&) noexcept
{
	return *this;
}
}
