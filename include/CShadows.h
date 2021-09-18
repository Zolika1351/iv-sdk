class CShadows
{
public:
	// zmenu chaos "It's bright in here":
	/*
		Vector3 v1 = {0,0,-1};
		Vector3 v2 = {0,1,0};
		CShadows::StoreStaticShadow(0, 0, 0x500, &v1, &v2, &pos, &color, 50, 0, 0, 5, 0.3, 3.0, -1, 0, (uint32_t)FindPlayerPed() + 1);
	*/
	// zmenu light spawning:
	// CShadows::StoreStaticShadow(0, 0, LightSources[i].castShadows ? 0x504 : 0x500, (int)&v1, (int)&v2, (int)&LightSources[i].position, (int)&LightSources[i].color, LightSources[i].intensity, 0, 0, LightSources[i].range, 0.3, 3.0, -1, 0, (uint32_t)FindPlayerPed() + 1);
	void StoreStaticShadow(uint32_t a1, uint32_t a2, uint32_t nFlags, CVector *pVec1, CVector* pVec2, CVector* vPos, CVector* vColor, float fIntensity, uint32_t texHash, uint32_t a10, float fRange, float a12, float a13, uint32_t a14, uint32_t a15, uint32_t nID)
	{
		return ((void(__cdecl*)(uint32_t, uint32_t, uint32_t, CVector*, CVector*, CVector*, CVector*, float, uint32_t, uint32_t, float, float, float, uint32_t, uint32_t, uint32_t))(AddressSetter::Get(0x4C60E0, 0x62E5F0)))(a1, a2, nFlags, pVec1, pVec2, vPos, vColor, fIntensity, texHash, a10, fRange, a12, a13, a14, a15, nID);
	}
};