#include "../../../include/IVSDK.cpp"

// every frame while in-game
void LoadTxdsLoop()
{
	static bool bFirstFrame = true;
	if (bFirstFrame)
	{
		// make the back of the radar an A button
		CTxdStore::PushCurrentTxd();
		int slot = CTxdStore::FindTxdSlot(rage::atStringHash("buttons"));
		CTxdStore::SetCurrentTxd(slot);

		CRadar::m_pRadarRingBack.SetTexture("A_BUTT");

		CTxdStore::PopCurrentTxd();

		// make the front of the radar an IV logo
		CTxdStore::PushCurrentTxd();
		slot = CTxdStore::AddTxdSlot("net");
		CTxdStore::AddRef(slot);
		if (CTxdStore::LoadTxd(slot, "platform:/textures/network"))
		{
			CTxdStore::SetCurrentTxd(slot);

			CRadar::m_pRadarRingFront.SetTexture("icon_gta");
		}
		CTxdStore::PopCurrentTxd();

		bFirstFrame = false;
	}
}

// ran after the sdk initializes, add all your hooks/events/etc here
void plugin::gameStartupEvent()
{
	plugin::processScriptsEvent::Add(LoadTxdsLoop);
}