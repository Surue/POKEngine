#pragma once
#include <functional>

namespace poke
{
	typedef std::function<void(void)> update_callback;

	class Singleton
	{
	public:
		static Singleton* Get();

		void AddCallbacks(const update_callback cb);

		void Update() const;
	private:
		update_callback callback_;

		Singleton();
	};
} //namespace poke


