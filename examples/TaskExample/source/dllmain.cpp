#include "../../../include/IVSDK.cpp"

uint8_t threadDummy[256];

// every frame while in-game
void plugin::processScriptsEvent()
{
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_L))
	{
		CTaskComplexWanderStandard* task = (CTaskComplexWanderStandard*)CPools::ms_pTaskPool->New();
		if (task)
		{
			task->New(2, 0, 1, 2.5, 1);
			// this needs to be set otherwise GivePedScriptedTask will attempt to read a nullptr
			CTheScripts::m_pCurrentThread = (uint32_t)&threadDummy;
			CTheScripts::GivePedScriptedTask(CPools::ms_pPedPool->GetIndex(FindPlayerPed()), task, 26);
		}
	}
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_K))
	{
		CTaskComplexDie* task = (CTaskComplexDie*)CPools::ms_pTaskPool->New();
		if (task)
		{
			task->New(0, 0, 44, 190, 4.0, 0.0, 1);
			// this needs to be set otherwise GivePedScriptedTask will attempt to read a nullptr
			CTheScripts::m_pCurrentThread = (uint32_t)&threadDummy;
			// TASK_DIE does this but it's not required
			//FindPlayerPed()->SetHealth(0.0, 0);
			CTheScripts::GivePedScriptedTask(CPools::ms_pPedPool->GetIndex(FindPlayerPed()), task, 5);
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