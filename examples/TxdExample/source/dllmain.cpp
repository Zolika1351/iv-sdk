#include "../../../include/IVSDK.cpp"

// every frame while in-game
void plugin::processScriptsEvent()
{
	static bool bFirstFrame = true;
	if (bFirstFrame)
	{
		// make the back of the radar an A button
		CTxdStore::PushCurrentTxd();
		int slot = CTxdStore::FindTxdSlot(CKeyGen::GetKey("buttons"));
		CTxdStore::SetCurrentTxd(slot);

		CRadar::m_pRadarRingBack.SetTexture("A_BUTT");

		CTxdStore::PopCurrentTxd();
		bFirstFrame = false;
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