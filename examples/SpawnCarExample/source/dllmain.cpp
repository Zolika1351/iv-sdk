#include "../../../include/IVSDK.cpp"

// every frame while in-game
void plugin::processScriptsEvent()
{
	// spawn an admiral if L is pressed
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_L))
	{
		CStreaming::ScriptRequestModel(rage::atStringHash("admiral"));
		CStreaming::LoadAllRequestedModels(0);
		CVector v = FindPlayerPed()->m_pMatrix->pos;
		int veh;
		// note: once new CAutomobile or CVehicleFactory is added, this should be changed to not use natives
		Scripting::CREATE_CAR(rage::atStringHash("admiral"), v.x, v.y, v.z, &veh, true);
		Scripting::WARP_CHAR_INTO_CAR(CPools::ms_pPedPool->GetIndex(FindPlayerPed()), veh);
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