#pragma once
#include "golang_defines.hpp"

#define GO_API __stdcall

typedef GoInt(GO_API *InitializeGoPlugin)();

// EVENTS
typedef void(GO_API *TickEvent)();