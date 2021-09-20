#include "../../../include/IVSDK.cpp"

uint8_t threadDummy[256];

// every frame while in-game
void plugin::processScriptsEvent()
{
	// note: tasks are still experimental, this will eventually crash but it does work before that
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_L))
	{
		CTask* task = (CTask*)CPools::ms_pTaskPool->New();
		if (task)
		{
			task = new CTaskComplexWanderStandard(2, 0, 1, 2.5, 1);
			// this needs to be set otherwise GivePedScriptedTask will attempt to read a nullptr
			CTheScripts::m_pCurrentThread = (uint32_t)&threadDummy;
			CTheScripts::GivePedScriptedTask(CPools::ms_pPedPool->GetIndex(FindPlayerPed()), task, 26);
		}
	}
}

// basically just DllMain but fancier and with the sdk initialized
void plugin::gameStartupEvent()
{

}

// right after gta.dat loads, put any extra loading related things here
void plugin::gameLoadEvent()
{

}