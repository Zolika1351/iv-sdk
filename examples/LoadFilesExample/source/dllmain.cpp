#include "../../../include/IVSDK.cpp"

void LoadExtraFiles()
{
	// WARNING: these will load AFTER the regular files, right after gta.dat loads
	// therefore no existing files will be overwritten in memory

	// load test.dat from the root folder just like a DLC content.dat
	CFileLoader::LoadLevel("test.dat", 0);
	// load mods.img from the mods folder
	CdStreamAddImage("mods/mods.img", 0, -1);
}

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	plugin::gameLoadEvent::Add(LoadExtraFiles);
}