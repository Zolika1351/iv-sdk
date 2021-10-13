#include "../../../include/IVSDK.cpp"

// every frame while in-game
void SpawnCarLoop()
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

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	plugin::processScriptsEvent::Add(SpawnCarLoop);
}