class CEntity;
class phInstGta;

struct tLineOfSightResults
{
	phInstGta* m_pInst = nullptr;						// 00-04 phInstGta pointer of hit entity
	uint8_t pad[0xC];									// 04-10
	CVector m_vEndPosition;								// 10-1C where it ended up
	uint32_t m_nUnkFlags;								// 1C-20 0x11
	CVector m_vUnk;										// 20-2C
	uint32_t m_nUnkFlags2;								// 2C-30 0x11
	CVector m_vUnk2;									// 30-3C
	uint32_t m_nUnkFlags3;								// 3C-40 0x11
	float m_fUnk1;										// 40-44
	float m_fUnk2;										// 44-48
	uint32_t m_nUnkFlags4;								// 48-4C 0x4F
	uint32_t m_nUnkFlags5;								// 4C-50 0x20000
	uint32_t m_nUnkFlags6;								// 50-54 0x10001
};
VALIDATE_SIZE(tLineOfSightResults, 0x54);
VALIDATE_OFFSET(tLineOfSightResults, m_pInst, 0x0);
VALIDATE_OFFSET(tLineOfSightResults, m_vEndPosition, 0x10);
VALIDATE_OFFSET(tLineOfSightResults, m_vUnk, 0x20);
VALIDATE_OFFSET(tLineOfSightResults, m_vUnk2, 0x30);

enum eLineOfSightFlags
{
	STATIC_COLLISION = 2,
	BUILDINGS = 4,
	VEHICLES = 8,
	PEDS_BOUNDING_BOX = 32,
	PEDS_COLLISION = 64,
	OBJECTS = 128,
};

class CWorld
{
public:
	static inline CPlayerInfo** Players = (CPlayerInfo**)AddressSetter::Get(0xDA7008, 0xD00498); // Players[32]
	static inline int32_t& PlayerInFocus = AddressSetter::GetRef<int32_t>(0xB1CC68, 0xB2E0B4);

	static void Add(CEntity* entity, bool bUnk)
	{
		((void(__cdecl*)(CEntity*, bool))(AddressSetter::Get(0x417350, 0x3CC640)))(entity, bUnk);
	}
	
	static void Remove(CEntity* entity, bool bUnk)
	{
		((void(__cdecl*)(CEntity*, bool))(AddressSetter::Get(0x4173C0, 0x3CC6B0)))(entity, bUnk);
	}

	static void RemoveFallenPeds()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x419270, 0x3CE740)))();
	}

	static void RemoveFallenCars()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x4194F0, 0x3CE9C0)))();
	}

	static void RemoveFallenObjects()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x419750, 0x3CEC20)))();
	}

	static bool ProcessLineOfSight(CVector* source, CVector* target, uint32_t* pUnk, tLineOfSightResults* pResults, uint32_t nFlags, uint32_t nUnk1, uint32_t nUnk2, uint32_t nSeeThroughShootThrough, uint32_t nUnk4)
	{
		// zmenu uses CWorld::ProcessLineOfSight(v, v2, 0, &ret, 142, 1, 0, 2, 4)
		// see/shoot 1 -> do see through check
		// see/shoot 2 -> do shoot through check
		return ((uint32_t(__cdecl*)(CVector*, CVector*, uint32_t*, tLineOfSightResults*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))(AddressSetter::Get(0x596D80, 0x52A400)))(source, target, pUnk, pResults, nFlags, nUnk1, nUnk2, nSeeThroughShootThrough, nUnk4);
	}
};