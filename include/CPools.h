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
class CTxdFile;
struct TxdDef;
struct IplDef;
class CQuadTreeNode;
class CPedTargetting;

class CPools
{
public:
	static inline auto& ms_pPedPool = AddressSetter::GetRef<CPool<CPed>*>(0x14A82AC, 0x14CB03C);
	static inline auto& ms_pVehiclePool = AddressSetter::GetRef<CPool<CVehicle>*>(0x1219240, 0xE52CD0);
	static inline auto& ms_pBuildingPool = AddressSetter::GetRef<CPool<CBuilding>*>(0x128FED0, 0xE4A5E8);
	static inline auto& ms_pObjectPool = AddressSetter::GetRef<CPool<CObject>*>(0xF50CE0, 0xE52B48);
	static inline auto& ms_pCameraPool = AddressSetter::GetRef<CPool<CCam>*>(0x1218020, 0xF68158);
	static inline auto& ms_pTaskPool = AddressSetter::GetRef<CPool<CTask>*>(0x124B01C, 0x126FE3C);
	static inline auto& ms_pInteriorInstPool = AddressSetter::GetRef<CPool<CInteriorInst>*>(0x125D2E4, 0xE54D74);
	static inline auto& ms_pVehicleStructPool = AddressSetter::GetRef<CPool<CVehicleStructure>*>(0x12D6594, 0x1001BCC);
	static inline auto& ms_pPedMoveBlendPool = AddressSetter::GetRef<CPool<CPedMoveBlendOnFoot>*>(0x14A82B4, 0x14CB044);
	static inline auto& ms_pDummyPedPool = AddressSetter::GetRef<CPool<CDummyPed>*>(0x14A82BC, 0x14CB04C);
	static inline auto& ms_pDummyTaskPool = AddressSetter::GetRef<CPool<CDummyTask>*>(0x1306E8C, 0x128AAC0);
	static inline auto& ms_pUnkPedDataPool = AddressSetter::GetRef<CPool<tPedData>*>(0x14A82B8, 0x14CB048);
	static inline auto& ms_pPedIntelligencePool = AddressSetter::GetRef<CPool<CPedIntelligenceNY>*>(0x14A82B0, 0x14CB040);
	static inline auto& ms_pAnimBlenderPool = AddressSetter::GetRef<CPool<CAnimBlender>*>(0x12397B0, 0xE4E6B0);
	static inline auto& ms_pFragInstNMGtaPool = AddressSetter::GetRef<CPool<fragInstNMGta>*>(0x1306660, 0x12767C8);
	static inline auto& ms_pPedDataPool = AddressSetter::GetRef<CPool<CPedDataNY>*>(0x14A82A8, 0x14CB038);
	static inline auto& ms_pQuadTreeNodePool = AddressSetter::GetRef<CPool<CQuadTreeNode>*>(0xF504D0, 0x127608C);
	static inline auto& ms_pTxdPool = AddressSetter::GetRef<CPool<TxdDef>*>(0xDD52D4, 0xE291E0);
	static inline auto& ms_pIplPool = AddressSetter::GetRef<CPool<IplDef>*>(0x128FF98, 0xF6E468);
	static inline auto& ms_pPedTargettingPool = AddressSetter::GetRef<CPool<CPedTargetting>*>(0x1311134, 0x12859EC);
};