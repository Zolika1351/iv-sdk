// arrays, etc. go here
namespace CleanAddressSetter
{
	void SetAll()
	{
		CWorld::Players = (CPlayerInfo**)Addresses::nPlayers;
		CGarage::m_sStoredCars = (CStoredCar*)Addresses::nm_sStoredCars;
		cHandlingDataMgr::HandlingData = (tHandlingData*)Addresses::nHandlingData;
		CModelInfo::ms_modelInfoPtrs = (CBaseModelInfo*)Addresses::nms_modelInfoPtrs;
	}
}