#include "../../../include/IVSDK.cpp"

// every frame while in-game
void plugin::processScriptsEvent()
{

}

// basically just DllMain but fancier and with the sdk initialized
void plugin::gameStartupEvent()
{

}

// right after gta.dat loads, put any extra loading related things here
void plugin::gameLoadEvent()
{
	// WARNING: these will load AFTER the regular files
	// therefore no existing files will be overwritten in memory

	// load test.dat from the root folder just like a DLC content.dat
	CFileLoader::LoadLevel("test.dat", 0);
	// load mods.img from the mods folder
	CdStreamAddImage("mods/mods.img", 0, -1);
}