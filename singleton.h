#pragma once

namespace poke
{
	class Singleton
	{
	public:
		static Singleton* Get();
	private:
		Singleton();
	};
} //namespace poke


