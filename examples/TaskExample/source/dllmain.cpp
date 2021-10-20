#include "../../../include/IVSDK.cpp"

uint8_t threadDummy[256];

// every frame while in-game
void TasksLoop()
{
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_L))
	{
		auto task = new CTaskComplexWanderStandard(2, 0, 1, 2.5, 1);
		if (task)
		{
			// this needs to be set otherwise GivePedScriptedTask will attempt to read a nullptr
			CTheScripts::m_pCurrentThread = (uint32_t)&threadDummy;
			CTheScripts::GivePedScriptedTask(CPools::ms_pPedPool->GetIndex(FindPlayerPed()), task, 26);
		}
	}
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_K))
	{
		auto task = new CTaskComplexDie(0, 0, 44, 190, 4.0, 0.0, 1);
		if (task)
		{
			// this needs to be set otherwise GivePedScriptedTask will attempt to read a nullptr
			CTheScripts::m_pCurrentThread = (uint32_t)&threadDummy;

			// TASK_DIE does this but it's not required
			//FindPlayerPed()->SetHealth(0.0, 0);

			CTheScripts::GivePedScriptedTask(CPools::ms_pPedPool->GetIndex(FindPlayerPed()), task, 5);
		}
	}
}

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	plugin::processScriptsEvent::Add(TasksLoop);
}