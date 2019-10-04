#include "singleton.h"
#include <iostream>


namespace poke
{
Singleton::Singleton() {}

Singleton* Singleton::Get()
{
	static Singleton instance;

	return &instance;
}

void Singleton::AddCallbacks(const update_callback cb)
{
	std::cout << "add callback\n";
	callback_ = cb;
}

void Singleton::Update() const
{
	std::cout << "call callback\n";
	callback_();
}
} //namespace poke
