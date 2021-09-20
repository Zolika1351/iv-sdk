#include "../../../include/IVSDK.cpp"

// every frame while in-game
void plugin::processScriptsEvent()
{
	// spawn m_y_multiplayer if L is pressed
	if (Scripting::IS_GAME_KEYBOARD_KEY_JUST_PRESSED(KEY_L))
	{
		int index;
		auto mdl = CModelInfo::GetModelInfo(rage::atStringHash("m_y_multiplayer"), &index);
		CStreaming::ScriptRequestModel(rage::atStringHash("m_y_multiplayer"));
		CStreaming::LoadAllRequestedModels(0);
		tSpawnData data = { 0, 0 };
		CMatrix mat = *FindPlayerPed()->m_pMatrix;
		mat.pos.x += 2;
		CPed* ped = PedFactory->CreatePed(&data, index, &mat, 1, 1);
		CWorld::Add(ped, 0);
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
