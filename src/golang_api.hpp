#pragma once
#include "golang_defines.hpp"
#include "ragemp-cppsdk/rage.hpp"

#define GO_API __stdcall

typedef void(GO_API *InitializeGoPlugin)(rage::IMultiplayer *mp);

// EVENTS
typedef void(GO_API *TickEvent)();