#define _CRT_SECURE_NO_WARNINGS
#define UNICODE
#pragma comment(lib, "version.lib")
#include <windows.h>
#include <stdint.h>
#include <string>
#include <list>
#include <d3dx9.h>
#include "injector/injector.hpp"

#include "Addresses.h"
#include "IVSDK.h"
#include "Scripting/Scripting.h"
#include "Hooks.h"

namespace plugin
{
	HMODULE GetCurrentModule()
	{
		HMODULE hModule = NULL;
		GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (LPCTSTR)GetCurrentModule, &hModule);
		return hModule;
	}

	// apparently the plugin unloads without this? wtf
	DWORD WINAPI DummyThread(HMODULE hModule)
	{
		while (true)
		{
			Sleep(1000);
		}
		FreeLibraryAndExitThread(hModule, 0);
		return 0;
	}
	uint32_t DoHook(uint32_t address, void(*Function)())
	{
		uint32_t origcall = (uint32_t)injector::ReadRelativeOffset(address + 1);

		injector::MakeCALL(address, Function);

		return origcall;
	}
	void InitHooks()
	{
		processScriptsEvent::returnAddress = DoHook(AddressSetter::Get(0x21601, 0x95141), processScriptsEvent::MainHook);
		gameLoadEvent::returnAddress = DoHook(AddressSetter::Get(0x4ADB38, 0x770748), gameLoadEvent::MainHook);
		processAutomobileEvent::callAddress = DoHook(AddressSetter::Get(0x7FE9C6, 0x652C26), processAutomobileEvent::MainHook);
	}
	void Init()
	{
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)DummyThread, GetCurrentModule(), 0, nullptr);
		if (!AddressSetter::bAddressesRead) AddressSetter::Init();
		if (gameVer != VERSION_NONE)
		{
			InitHooks();

			gameStartupEvent();
		}
	}
}

BOOL APIENTRY DllMain(HMODULE, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) plugin::Init();
	return TRUE;
}

