#pragma once
#include "golang_defines.h"
#include <windows.h>
#include "sdk/rage.hpp"
#include "golang_api.h"

class GoPlugin
	: public rage::IEventHandler,
	public rage::ITickHandler
{
public:
	GoPlugin(LPCWSTR path);
	~GoPlugin();
	int TryInitialize(rage::IMultiplayer *mp);

	virtual rage::ITickHandler *GetTickHandler()
	{
		return this;
	}

	virtual void Tick()
	{
		if (_tickHandler != nullptr) _tickHandler();
	}

private:
	void HookEvents(rage::IMultiplayer *mp);
	WCHAR _path[MAX_PATH];
	HINSTANCE _dllHandle;

	TickEvent _tickHandler;
};

