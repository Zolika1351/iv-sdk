class CPools
{
public:
	static inline CPool*& ms_pPedPool = *(CPool**)nullptr;
	static inline CPool*& ms_pVehiclePool = *(CPool**)nullptr;
	static inline CPool*& ms_pBuildingPool = *(CPool**)nullptr;
	static inline CPool*& ms_pObjectPool = *(CPool**)nullptr;
	static inline CPool*& ms_pCameraPool = *(CPool**)nullptr;
};