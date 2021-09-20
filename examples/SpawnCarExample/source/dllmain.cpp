#include "../../../include/IVSDK.cpp"

// every frame while in-game
void plugin::processScriptsEvent()
{
	// spawn an admiral if L is pressed
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_L))
	{
		int index;
		auto mdl = CModelInfo::GetModelInfo(rage::atStringHash("admiral"), &index);
		CStreaming::ScriptRequestModel(rage::atStringHash("admiral"));
		CStreaming::LoadAllRequestedModels(0);
		CMatrix mat = *FindPlayerPed()->m_pMatrix;
		mat.pos.x += 2;
		CVehicle* veh = VehicleFactory->CreateVehicle(index, RANDOM_VEHICLE, &mat, 1);
		CWorld::Add(veh, 0);
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
