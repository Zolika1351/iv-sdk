class CPools
{
public:
	static inline CPool*& ms_pPedPool = AddressSetter::GetRef<CPool*>(0x14A82AC, 0x14CB03C);
	static inline CPool*& ms_pVehiclePool = AddressSetter::GetRef<CPool*>(0x1219240, 0xE52CD0);
	static inline CPool*& ms_pBuildingPool = AddressSetter::GetRef<CPool*>(0x128FED0, 0xE4A5E8);
	static inline CPool*& ms_pObjectPool = AddressSetter::GetRef<CPool*>(0xF50CE0, 0xE52B48);
	static inline CPool*& ms_pCameraPool = AddressSetter::GetRef<CPool*>(0x1218020, 0xF68158);
};