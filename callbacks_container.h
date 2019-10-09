#pragma once

#include "callback.h"

namespace poke
{
struct CallbackContainer
{
	Callback<VoidCallback> initCallback{};
	Callback<VoidCallback> updateCallback{};
	Callback<VoidCallback> updatePhysicCallback{};
	Callback<VoidCallback> renderCallback{};
	Callback<VoidCallback> destroyCallback{};
};
}
