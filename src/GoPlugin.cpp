#include <iostream>
#include <filesystem> 

#include "GoPlugin.hpp"

namespace fs = std::experimental::filesystem;

std::string last(std::string const& str, std::string const& delimiter) { return str.substr(str.find_last_of(delimiter) + delimiter.size()); }

GoPlugin::GoPlugin()
{
	// Iterate all DLLs
	std::cout << "Initializing RageGo.." << std::endl;

	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	std::string path = std::string(buffer).substr(0, pos);
	path.append("\\gopackages\\");

	for (const auto & p : fs::directory_iterator("gopackages"))
	{
		const auto path_str = p.path().string();
		const auto filename = last(path_str, "\\");
		if (filename.find(".dll") == std::string::npos) continue;

		std::cout << "Loading '" << filename << "'.." << std::endl;

		if (!InitPackage(path_str)) std::cout << "Error, unable to initialize '" << filename << "'!" << std::endl;
		std::cout << std::endl;
	}
}

bool GoPlugin::InitPackage(const std::string& path)
{
	WIN32_FIND_DATA data;

	std::wstring wstring_path = std::wstring(path.begin(), path.end());
	const LPCWSTR lpcwstr_path = wstring_path.c_str();

	HINSTANCE dll_handle = LoadLibrary(lpcwstr_path);

	if (dll_handle != nullptr)
	{
		InitializeGoPlugin init = GetProcAddress(dll_handle, "main");
		if (init == nullptr) std::cout << "Error, missing 'main' entry point function!" << std::endl;
		init();
	}
	return true;
}

void GoPlugin::Terminate()
{
	// FreeLibrary
}

void GoPlugin::SetMultiplayer(rage::IMultiplayer *mp)
{
	this->m_mp = mp;
	mp->AddEventHandler(dynamic_cast<rage::IEventHandler*>(&RAGEMP::EventHandler::GetInstance()));
}

// todo: event invocation