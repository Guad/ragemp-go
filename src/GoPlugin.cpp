#include "GoPlugin.h"

#include <iostream>

GoPlugin::GoPlugin(LPCWSTR path)
{
	wcscpy_s(this->_path, MAX_PATH, path);
}

GoPlugin::~GoPlugin()
{
	
}

int GoPlugin::TryInitialize(rage::IMultiplayer *mp)
{
	_dllHandle = LoadLibrary(this->_path);

	if (_dllHandle != NULL)
	{
		InitializeGoPlugin init = (InitializeGoPlugin) GetProcAddress(_dllHandle, "InitializeGoPlugin");

		if (init != NULL)
		{			
			int result = (int) init();

			if (!result) {
				HookEvents(mp);
			}

			return result;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 1;
	}
}

void GoPlugin::HookEvents(rage::IMultiplayer * mp)
{
	std::cout << "Hooking up events." << std::endl;
	FARPROC proc;
	if ((proc = GetProcAddress(_dllHandle, "TickEvent")))
	{
		this->_tickHandler = (TickEvent)proc;
		std::cout << "Found tickevent" << std::endl;

		mp->AddEventHandler(this);

		rage::IWorld &w = mp->GetWorld();
		rage::IWorld *ptrW = &w;
	}
	
}
