// this is absolutely abhorrent but it's the only way I've found to get this to work

#define DIRTYSETADDRFUNCTION(ptr, funcName) void __declspec(naked) funcName() { __asm { mov eax, ptr } }
#define DIRTYSETADDR(funcName, addr) *(uint32_t*)(GetAddressFromMoveEAXFunction((uint32_t)&funcName)) = addr;

namespace DirtyAddressSetter
{
	uint32_t GetAddressFromMoveEAXFunction(uint32_t Function)
	{
		return *(uint32_t*)(Function + 1);
	}
	DIRTYSETADDRFUNCTION(CWorld::PlayerInFocus, PlayerInFocus)
	DIRTYSETADDRFUNCTION(CRadar::m_radarRange, RadarRange)
	DIRTYSETADDRFUNCTION(CPools::ms_pBuildingPool, BuildingPool)
	DIRTYSETADDRFUNCTION(CPools::ms_pObjectPool, ObjectPool)
	DIRTYSETADDRFUNCTION(CPools::ms_pPedPool, PedPool)
	DIRTYSETADDRFUNCTION(CPools::ms_pVehiclePool, VehiclePool)
	DIRTYSETADDRFUNCTION(CTimer::m_CodePause, m_CodePause)
	DIRTYSETADDRFUNCTION(CTimer::m_UserPause, m_UserPause)
	DIRTYSETADDRFUNCTION(CTimer::m_FrameCounter, m_FrameCounter)
	DIRTYSETADDRFUNCTION(CTimer::m_snTimeInMilliseconds, m_snTimeInMilliseconds)
	DIRTYSETADDRFUNCTION(CTimer::ms_fMinTimeStep, ms_fMinTimeStep)
	DIRTYSETADDRFUNCTION(CTimer::ms_fMaxTimeStep, ms_fMaxTimeStep)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeStep, ms_fTimeStep)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeStepNonClipped, ms_fTimeStepNonClipped)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeScale, ms_fTimeScale)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeScale2, ms_fTimeScale2)
	DIRTYSETADDRFUNCTION(CTimer::ms_fTimeScale3, ms_fTimeScale3)
	void SetAll()
	{
		DIRTYSETADDR(PlayerInFocus, Addresses::nPlayerInFocus)
		DIRTYSETADDR(RadarRange, Addresses::nm_radarRange)
		DIRTYSETADDR(BuildingPool, Addresses::nms_pBuildingPool)
		DIRTYSETADDR(ObjectPool, Addresses::nms_pObjectPool)
		DIRTYSETADDR(PedPool, Addresses::nms_pPedPool)
		DIRTYSETADDR(VehiclePool, Addresses::nms_pVehiclePool)
		DIRTYSETADDR(m_CodePause, Addresses::nm_CodePause)
		DIRTYSETADDR(m_UserPause, Addresses::nm_UserPause)
		DIRTYSETADDR(m_FrameCounter, Addresses::nm_FrameCounter)
		DIRTYSETADDR(m_snTimeInMilliseconds, Addresses::nm_snTimeInMilliseconds)
		DIRTYSETADDR(ms_fMinTimeStep, Addresses::nms_fMinTimeStep)
		DIRTYSETADDR(ms_fMaxTimeStep, Addresses::nms_fMaxTimeStep)
		DIRTYSETADDR(ms_fTimeStep, Addresses::nms_fTimeStep)
		DIRTYSETADDR(ms_fTimeStepNonClipped, Addresses::nms_fTimeStepNonClipped)
		DIRTYSETADDR(ms_fTimeScale, Addresses::nms_fTimeScale)
		DIRTYSETADDR(ms_fTimeScale2, Addresses::nms_fTimeScale2)
		DIRTYSETADDR(ms_fTimeScale3, Addresses::nms_fTimeScale3)
	}
}