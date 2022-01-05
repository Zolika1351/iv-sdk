class CPed;
class CVehicle;
class CBuilding;
class CObject;
class CCam;
class CTask;
class CInteriorInst;
class CVehicleStructure;

class CPools
{
public:
	static inline CPool<CPed>*& ms_pPedPool							 = AddressSetter::GetRef<CPool<CPed>*>(0x14A82AC, 0x14CB03C);
	static inline CPool<CVehicle>*& ms_pVehiclePool					 = AddressSetter::GetRef<CPool<CVehicle>*>(0x1219240, 0xE52CD0);
	static inline CPool<CBuilding>*& ms_pBuildingPool				 = AddressSetter::GetRef<CPool<CBuilding>*>(0x128FED0, 0xE4A5E8);
	static inline CPool<CObject>*& ms_pObjectPool					 = AddressSetter::GetRef<CPool<CObject>*>(0xF50CE0, 0xE52B48);
	static inline CPool<CCam>*& ms_pCameraPool						 = AddressSetter::GetRef<CPool<CCam>*>(0x1218020, 0xF68158);
	static inline CPool<CTask>*& ms_pTaskPool						 = AddressSetter::GetRef<CPool<CTask>*>(0x124B01C, 0x126FE3C);
	static inline CPool<CInteriorInst>*& ms_pInteriorInstPool		 = AddressSetter::GetRef<CPool<CInteriorInst>*>(0x125D2E4, 0xE54D74);
	static inline CPool<CVehicleStructure>*& ms_pVehicleStructPool	 = AddressSetter::GetRef<CPool<CVehicleStructure>*>(0x12D6594, 0x1001BCC);
};