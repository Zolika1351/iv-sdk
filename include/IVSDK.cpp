#define _CRT_SECURE_NO_WARNINGS
#define UNICODE
#pragma comment(lib, "version.lib")
#include <windows.h>
#include <stdint.h>
#include <string>
#include "injector/injector.hpp"

#include "Addresses.h"
#include "IVSDK.h"
#include "Scripting/Scripting.h"
#include "Hooks.h"
#include "DirtyAddressSet.h"
#include "CleanAddressSet.h"

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

	// this is probably terrible
	uint32_t GetVersionFromEXE()
	{
		TCHAR szFileName[MAX_PATH];

		GetModuleFileName(NULL, szFileName, MAX_PATH);

		DWORD  verHandle = 0;
		UINT   size = 0;
		LPBYTE lpBuffer = NULL;
		DWORD  verSize = GetFileVersionInfoSize(szFileName, &verHandle);

		if (verSize != NULL)
		{
			LPSTR verData = new char[verSize];

			if (GetFileVersionInfo(szFileName, verHandle, verSize, verData))
			{
				if (VerQueryValue(verData, TEXT("\\"), (VOID FAR * FAR*) & lpBuffer, &size))
				{
					if (size)
					{
						VS_FIXEDFILEINFO* verInfo = (VS_FIXEDFILEINFO*)lpBuffer;
						if (verInfo->dwSignature == 0xfeef04bd)
						{
							std::string str = std::to_string((verInfo->dwFileVersionMS >> 16) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionMS >> 0) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionLS >> 16) & 0xffff);
							str += std::to_string((verInfo->dwFileVersionLS >> 0) & 0xffff);
							delete[] verData;
							return std::stoi(str);
						}
					}
				}
			}
			delete[] verData;
		}
		return 0;
	}
	// 1040 is too different to support in this project
	void DetermineVersion()
	{
		uint32_t ver = GetVersionFromEXE();
		switch (ver)
		{
		case 1070:
			gameVer = VERSION_1070;
			break;
		case 1080:
			gameVer = VERSION_1080;
			break;
		default:
			gameVer = VERSION_NONE;
			break;
		}
	}
	void PickAddressesByVersion()
	{
		gBaseAddress = (uint32_t)GetModuleHandle(NULL);
		switch (gameVer)
		{
		case VERSION_1070:
			Addresses::nProcessScriptsEvent = gBaseAddress + 0x21601;
			Addresses::nGameLoadEvent = gBaseAddress + 0x4ADB38;
			Addresses::nGetPadFromPlayer = gBaseAddress + 0x5BE5D0;
			Addresses::nGetPad = gBaseAddress + 0x3C3900;
			Addresses::nGetPlayerInfo = gBaseAddress + 0x417F20;
			Addresses::nPlayers = gBaseAddress + 0xDA7008;
			Addresses::nPlayerInFocus = gBaseAddress + 0xB1CC68;
			Addresses::nm_radarRange = gBaseAddress + 0xD9ED40;
			Addresses::nPoolGetAt = gBaseAddress + 0x26700;
			Addresses::nPoolGetIndex = gBaseAddress + 0x47230;
			Addresses::nms_pBuildingPool = gBaseAddress + 0x128FED0;
			Addresses::nms_pObjectPool = gBaseAddress + 0xF50CE0;
			Addresses::nms_pPedPool = gBaseAddress + 0x14A82AC;
			Addresses::nms_pVehiclePool = gBaseAddress + 0x1219240;
			Addresses::nm_sStoredCars = gBaseAddress + 0xF54A88;
			Addresses::nHandlingData = gBaseAddress + 0x11E3BF0;
			Addresses::nGetModelInfo = gBaseAddress + 0x58AAE0;
			Addresses::nGetKey = gBaseAddress + 0x1B1C30;
			Addresses::nFindNativeAddress = gBaseAddress + 0x1A76D0;
			Addresses::nGetConstrainedCollider = gBaseAddress + 0x5E7080;
			Addresses::nm_CodePause = gBaseAddress + 0xDDDF41;
			Addresses::nm_UserPause = gBaseAddress + 0xDDDF42;
			Addresses::nm_FrameCounter = gBaseAddress + 0xDDDF38;
			Addresses::nm_snTimeInMilliseconds = gBaseAddress + 0xDDDE74;
			Addresses::nms_fMinTimeStep = gBaseAddress + 0xB1D9E4;
			Addresses::nms_fMaxTimeStep = gBaseAddress + 0xB1D9E8;
			Addresses::nms_fTimeStep = gBaseAddress + 0xDDDE7C;
			Addresses::nms_fTimeStepNonClipped = gBaseAddress + 0xDDDEBC;
			Addresses::nms_fTimeScale = gBaseAddress + 0xB1D9D8;
			Addresses::nms_fTimeScale2 = gBaseAddress + 0xB1D9DC;
			Addresses::nms_fTimeScale3 = gBaseAddress + 0xB1D9E0;
			Addresses::nLoadAllRequestedModels = gBaseAddress + 0x432C20;
			Addresses::nScriptRequestModel = gBaseAddress + 0x76C3D0;
			Addresses::nRequestModel = gBaseAddress + 0x432C40;
			Addresses::nLoadLevel = gBaseAddress + 0x4D79A0;
			Addresses::nGameInitialise = gBaseAddress + 0x4ADA50;
			Addresses::nCdStreamAddImage = gBaseAddress + 0x497730;
			Addresses::nms_disableStreaming = gBaseAddress + 0xE1DFAA;
			Addresses::nms_modelInfoPtrs = gBaseAddress + 0x11F73B0;
			Addresses::nms_RadarTrace = gBaseAddress + 0xD9ED50;
			Addresses::nms_pCameraPool = gBaseAddress + 0x1218020;
			Addresses::nms_ExplosionInfo = gBaseAddress + 0x11C0778;
			Addresses::nms_HudColour = gBaseAddress + 0xDE4D40;
			Addresses::nms_vehicleColourTable = gBaseAddress + 0x12D65A8;
			Addresses::nWorldRemove = gBaseAddress + 0x4173C0;
			Addresses::nm_pedLodDistanceHigh = gBaseAddress + 0xB36D8C;
			Addresses::nm_pedInCarLodDistanceHigh = gBaseAddress + 0xB36D90;
			Addresses::nm_pedLodDistanceMed = gBaseAddress + 0xB36D94;
			Addresses::nm_pedLodDistanceLow = gBaseAddress + 0xB36D98;
			Addresses::nm_pedLodDistanceVlow = gBaseAddress + 0xB36D9C;
			Addresses::nm_pedLodDistanceSlod = gBaseAddress + 0xB36DA0;
			Addresses::nm_carLodDistanceHigh = gBaseAddress + 0xB33A44;
			Addresses::nm_carLodDistanceMed = gBaseAddress + 0xB33A48;
			Addresses::nFindPlayerCentreOfWorld = gBaseAddress + 0x418100;
			Addresses::nRemoveFallenPeds = gBaseAddress + 0x419270;
			Addresses::nRemoveFallenCars = gBaseAddress + 0x4194F0;
			Addresses::nRemoveFallenObjects = gBaseAddress + 0x419750;
			Addresses::nGetIsPaused = gBaseAddress + 0x44370;
			Addresses::nIsNetworkGameRunning = gBaseAddress + 0x62F90;
			Addresses::nIsNetworkSession = gBaseAddress + 0x3B79E0;
			Addresses::nm_bNetworkSession = gBaseAddress + 0xCF806C;
			Addresses::nm_nCurrentEpisode = gBaseAddress + 0xCF8044;
			Addresses::nm_nCurrentEpisodeMenu = gBaseAddress + 0xCF8078;
			Addresses::nKillPlayerOutsideWorld = gBaseAddress + 0x478F7D;
			Addresses::nm_nNetworkStatus = gBaseAddress + 0x13E49B8;
			Addresses::nStoreStaticShadow = gBaseAddress + 0x4C60E0;
			Addresses::nms_aWeaponNames = gBaseAddress + 0xB27A88;
			Addresses::nms_WeaponInfo = gBaseAddress + 0x1140A20;
			Addresses::nGetWeaponInfo = gBaseAddress + 0x524E80;
			Addresses::nMakeDirty = gBaseAddress + 0x5D3E90;
			break;
		case VERSION_1080:
			Addresses::nProcessScriptsEvent = gBaseAddress + 0x95141;
			Addresses::nGameLoadEvent = gBaseAddress + 0x770748;
			Addresses::nGetPadFromPlayer = gBaseAddress + 0x596F80;
			Addresses::nGetPad = gBaseAddress + 0x46A110;
			Addresses::nGetPlayerInfo = gBaseAddress + 0x3CD210;
			Addresses::nPlayers = gBaseAddress + 0xD00498;
			Addresses::nPlayerInFocus = gBaseAddress + 0xB2E0B4;
			Addresses::nm_radarRange = gBaseAddress + 0xDE8390;
			Addresses::nPoolGetAt = gBaseAddress + 0x92E00;
			Addresses::nPoolGetIndex = gBaseAddress + 0xAFF10;
			Addresses::nms_pBuildingPool = gBaseAddress + 0xE4A5E8;
			Addresses::nms_pObjectPool = gBaseAddress + 0xE52B48;
			Addresses::nms_pPedPool = gBaseAddress + 0x14CB03C;
			Addresses::nms_pVehiclePool = gBaseAddress + 0xE52CD0;
			Addresses::nm_sStoredCars = gBaseAddress + 0xECBE00;
			Addresses::nHandlingData = gBaseAddress + 0x12773B0;
			Addresses::nGetModelInfo = gBaseAddress + 0x4DD2D0;
			Addresses::nGetKey = gBaseAddress + 0x5CF50;
			Addresses::nFindNativeAddress = gBaseAddress + 0x226AF0;
			Addresses::nGetConstrainedCollider = gBaseAddress + 0x505110;
			Addresses::nm_CodePause = gBaseAddress + 0xCFCC3A;
			Addresses::nm_UserPause = gBaseAddress + 0xCFCC39;
			Addresses::nm_FrameCounter = gBaseAddress + 0xCFCC30;
			Addresses::nm_snTimeInMilliseconds = gBaseAddress + 0xCFCB6C;
			Addresses::nms_fMinTimeStep = gBaseAddress + 0xB2E09C;
			Addresses::nms_fMaxTimeStep = gBaseAddress + 0xB2E0A0;
			Addresses::nms_fTimeStep = gBaseAddress + 0xCFCB74;
			Addresses::nms_fTimeStepNonClipped = gBaseAddress + 0xCFCBB4;
			Addresses::nms_fTimeScale = gBaseAddress + 0xB2E090;
			Addresses::nms_fTimeScale2 = gBaseAddress + 0xB2E094;
			Addresses::nms_fTimeScale3 = gBaseAddress + 0xB2E098;
			Addresses::nLoadAllRequestedModels = gBaseAddress + 0x4B4BB0;
			Addresses::nScriptRequestModel = gBaseAddress + 0x7191D0;
			Addresses::nRequestModel = gBaseAddress + 0x4B4BD0;
			Addresses::nLoadLevel = gBaseAddress + 0x6CBE60;
			Addresses::nGameInitialise = gBaseAddress + 0x770660;
			Addresses::nCdStreamAddImage = gBaseAddress + 0x622BE0;
			Addresses::nms_disableStreaming = gBaseAddress + 0xF997D2;
			Addresses::nms_modelInfoPtrs = gBaseAddress + 0xE2C168;
			Addresses::nms_RadarTrace = gBaseAddress + 0xDE83A0;
			Addresses::nms_pCameraPool = gBaseAddress + 0xF68158;
			Addresses::nms_ExplosionInfo = gBaseAddress + 0xEFD0B8;
			Addresses::nms_HudColour = gBaseAddress + 0xDE8038;
			Addresses::nms_vehicleColourTable = gBaseAddress + 0x1001BE0;
			Addresses::nWorldRemove = gBaseAddress + 0x3CC6B0;
			Addresses::nm_pedLodDistanceHigh = gBaseAddress + 0xB5C98C;
			Addresses::nm_pedInCarLodDistanceHigh = gBaseAddress + 0xB5C990;
			Addresses::nm_pedLodDistanceMed = gBaseAddress + 0xB5C994;
			Addresses::nm_pedLodDistanceLow = gBaseAddress + 0xB5C998;
			Addresses::nm_pedLodDistanceVlow = gBaseAddress + 0xB5C99C;
			Addresses::nm_pedLodDistanceSlod = gBaseAddress + 0xB5C9A0;
			Addresses::nm_carLodDistanceHigh = gBaseAddress + 0xB4149C;
			Addresses::nm_carLodDistanceMed = gBaseAddress + 0xB414A0;
			Addresses::nFindPlayerCentreOfWorld = gBaseAddress + 0x3CD3F0;
			Addresses::nRemoveFallenPeds = gBaseAddress + 0x3CE740;
			Addresses::nRemoveFallenCars = gBaseAddress + 0x3CE9C0;
			Addresses::nRemoveFallenObjects = gBaseAddress + 0x3CEC20;
			Addresses::nGetIsPaused = gBaseAddress + 0xAD0B0;
			Addresses::nIsNetworkGameRunning = gBaseAddress + 0x2C1A10;
			Addresses::nIsNetworkSession = gBaseAddress + 0x3D4590;
			Addresses::nm_bNetworkSession = gBaseAddress + 0xD2D77C;
			Addresses::nm_nCurrentEpisode = gBaseAddress + 0xD2D754;
			Addresses::nm_nCurrentEpisodeMenu = gBaseAddress + 0xD2D788;
			Addresses::nKillPlayerOutsideWorld = gBaseAddress + 0x4B59D0;
			Addresses::nm_nNetworkStatus = gBaseAddress + 0x1395524;
			Addresses::nStoreStaticShadow = gBaseAddress + 0x62E5F0;
			Addresses::nms_aWeaponNames = gBaseAddress + 0xB3ECA8;
			Addresses::nms_WeaponInfo = gBaseAddress + 0xE4A600;
			Addresses::nGetWeaponInfo = gBaseAddress + 0x4DDEB0;
			Addresses::nMakeDirty = gBaseAddress + 0x4FE1E0;
			break;
		default:
			break;
		}
	}
	uint32_t DoHook(uint32_t address, void(*Function)())
	{
		uint32_t origcall = (uint32_t)injector::ReadRelativeOffset(address + 1);
		injector::MakeCALL(address, Function);
		return origcall;
	}
	void InitHooks()
	{
		Addresses::nProcessScriptsEventRet = DoHook(Addresses::nProcessScriptsEvent, processScriptsEventHook);
		Addresses::nGameLoadEventRet = DoHook(Addresses::nGameLoadEvent, gameLoadEventHook);
		DirtyAddressSetter::SetAll();
		CleanAddressSetter::SetAll();
	}
	void Init()
	{
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)DummyThread, GetCurrentModule(), 0, nullptr);
		DetermineVersion();
		if (gameVer != VERSION_NONE)
		{
			PickAddressesByVersion();
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

