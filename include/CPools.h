class CPed;
class CVehicle;
class CBuilding;
class CObject;
class CCam;
class CTask;
class CInteriorInst;
class CVehicleStructure;
class CPedMoveBlendOnFoot;
class CDummyPed;
class CDummyTask;
class tPedData;
class CPedIntelligenceNY;
class CAnimBlender;
class fragInstNMGta;
class CPedDataNY;

class CPools
{
public:
	static inline CPool<CPed>*& ms_pPedPool								= AddressSetter::GetRef<CPool<CPed>*>(0x14A82AC, 0x14CB03C);
	static inline CPool<CVehicle>*& ms_pVehiclePool						= AddressSetter::GetRef<CPool<CVehicle>*>(0x1219240, 0xE52CD0);
	static inline CPool<CBuilding>*& ms_pBuildingPool					= AddressSetter::GetRef<CPool<CBuilding>*>(0x128FED0, 0xE4A5E8);
	static inline CPool<CObject>*& ms_pObjectPool						= AddressSetter::GetRef<CPool<CObject>*>(0xF50CE0, 0xE52B48);
	static inline CPool<CCam>*& ms_pCameraPool							= AddressSetter::GetRef<CPool<CCam>*>(0x1218020, 0xF68158);
	static inline CPool<CTask>*& ms_pTaskPool							= AddressSetter::GetRef<CPool<CTask>*>(0x124B01C, 0x126FE3C);
	static inline CPool<CInteriorInst>*& ms_pInteriorInstPool			= AddressSetter::GetRef<CPool<CInteriorInst>*>(0x125D2E4, 0xE54D74);
	static inline CPool<CVehicleStructure>*& ms_pVehicleStructPool		= AddressSetter::GetRef<CPool<CVehicleStructure>*>(0x12D6594, 0x1001BCC);
	static inline CPool<CPedMoveBlendOnFoot>*& ms_pPedMoveBlendPool		= AddressSetter::GetRef<CPool<CPedMoveBlendOnFoot>*>(0x14A82B4, 0x14CB044);
	static inline CPool<CDummyPed>*& ms_pDummyPedPool					= AddressSetter::GetRef<CPool<CDummyPed>*>(0x14A82BC, 0x14CB04C);
	static inline CPool<CDummyTask>*& ms_pDummyTaskPool					= AddressSetter::GetRef<CPool<CDummyTask>*>(0x1306E8C, 0x128AAC0);
	static inline CPool<tPedData>*& ms_pUnkPedDataPool					= AddressSetter::GetRef<CPool<tPedData>*>(0x14A82B8, 0x14CB048);
	static inline CPool<CPedIntelligenceNY>*& ms_pPedIntelligencePool	= AddressSetter::GetRef<CPool<CPedIntelligenceNY>*>(0x14A82B0, 0x14CB040);
	static inline CPool<CAnimBlender>*& ms_pAnimBlenderPool				= AddressSetter::GetRef<CPool<CAnimBlender>*>(0x12397B0, 0xE4E6B0);
	static inline CPool<fragInstNMGta>*& ms_pFragInstNMGtaPool			= AddressSetter::GetRef<CPool<fragInstNMGta>*>(0x1306660, 0x12767C8);
	static inline CPool<CPedDataNY>*& ms_pPedDataPool					= AddressSetter::GetRef<CPool<CPedDataNY>*>(0x14A82A8, 0x14CB038);
};