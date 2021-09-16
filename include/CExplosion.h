struct tExplosionInfo
{
	float m_fDamageAtCentre;						// 00-04
	float m_fDamageAtEdge;							// 04-08
	float m_fNetworkPlayerModifier;					// 08-0C
	float m_fNetworkPedModifier;					// 0C-10
	float m_fEndRadius;								// 10-14
	float m_fInitSpeed;								// 14-18
	float m_fDecayFactor;							// 18-1C
	float m_fForceFactor;							// 1C-20
	float m_fRagdollModifier;						// 20-24
	uint32_t m_nFxHash;								// 24-28
	uint32_t m_nFxAirHash;							// 28-2C
	float m_fFxScale;								// 2C-30
	float m_fDirectedWidth;							// 30-34
	float m_fDirectedLife;							// 34-38
	uint32_t m_nNumFiresMin;						// 38-3C
	uint32_t m_nNumFiresMax;						// 3C-40
	float m_fFireRangeMin;							// 40-44
	float m_fFireRangeMax;							// 44-48
	float m_fCameraShake;							// 48-4C
	uint32_t m_nWeaponType;							// 4C-50
	uint32_t m_nInfinite;							// 50-54
	float m_fLightsR;								// 54-58
	float m_fLightsG;								// 58-5C
	float m_fLightsB;								// 5C-60
	float m_fLightsScale;							// 60-64
	float m_fLightsRange;							// 64-68
	float m_fLightsTime;							// 68-6C
	uint32_t m_nType;								// 6C-70
};
VALIDATE_SIZE(tExplosionInfo, 0x70);

class CExplosion
{
public:
	static inline tExplosionInfo* ms_ExplosionInfo; // ms_ExplosionInfo[25]
};