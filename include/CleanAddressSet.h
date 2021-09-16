// arrays, etc. go here
namespace CleanAddressSetter
{
	void SetAll()
	{
		CWorld::Players = (CPlayerInfo**)Addresses::nPlayers;
		CGarage::m_sStoredCars = (CStoredCar*)Addresses::nm_sStoredCars;
		cHandlingDataMgr::HandlingData = (tHandlingData*)Addresses::nHandlingData;
		CModelInfo::ms_modelInfoPtrs = (CBaseModelInfo**)Addresses::nms_modelInfoPtrs;
		CRadar::ms_RadarTrace = (sRadarTrace**)Addresses::nms_RadarTrace;
		CExplosion::ms_ExplosionInfo = (tExplosionInfo*)Addresses::nms_ExplosionInfo;
		CHudColours::ms_HudColour = (CHudColour*)Addresses::nms_HudColour;
		CVehicleModelInfo::ms_vehicleColourTable = (CRGBA*)Addresses::nms_vehicleColourTable;
		CWeaponInfo::ms_aWeaponNames = (char**)Addresses::nms_aWeaponNames;
		CWeaponInfo::ms_WeaponInfo = (CWeaponInfo*)Addresses::nms_WeaponInfo;
	}
}