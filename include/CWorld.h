class CEntity;

// todo: look into this, don't even know the exact size currently
struct tLineOfSightResults
{
	uint32_t m_unk0_1 = 0;
	uint32_t m_unkdword0_1;
	uint32_t m_unkdword4_2;
	uint32_t m_unkdword8_3;
	uint32_t m_unkdword0_4;
	uint32_t m_unkdword4_5;
	uint32_t m_unkdword8_6;
	uint32_t m_unkdword0_7;
	uint32_t m_unkdword4_8;
	uint32_t m_unkdword8_9;
	uint32_t m_unk0_2 = 0;
	uint32_t m_unk0_3 = 0;
	uint32_t m_unk0_4 = 0;
	int32_t m_unkneg1_1 = -1;
	uint32_t m_unk0_5 = 0;
	uint32_t m_unk0_6 = 0;
	uint32_t m_unk0_7 = 0;

	uint8_t pad[0x40];
};

class CWorld
{
public:
	static inline CPlayerInfo** Players; // Players[32]
	static inline int32_t& PlayerInFocus = *(int32_t*)nullptr;

	static void Remove(CEntity* entity, bool bUnk)
	{
		((void(__cdecl*)(CEntity*, bool))(Addresses::nWorldRemove))(entity, bUnk);
	}

	static void RemoveFallenPeds()
	{
		((void(__cdecl*)())(Addresses::nRemoveFallenPeds))();
	}

	static void RemoveFallenCars()
	{
		((void(__cdecl*)())(Addresses::nRemoveFallenCars))();
	}

	static void RemoveFallenObjects()
	{
		((void(__cdecl*)())(Addresses::nRemoveFallenObjects))();
	}

	static bool ProcessLineOfSight(CVector* source, CVector* target, uint32_t* pUnk, tLineOfSightResults* pResults, uint32_t nFlags, uint32_t nUnk1, uint32_t nUnk2, uint32_t nUnk3, uint32_t nUnk4)
	{
		// zmenu uses CWorld::ProcessLineOfSight(v, v2, 0, &ret, 142, 1, 0, 2, 4)
		return ((uint32_t(__cdecl*)(CVector*, CVector*, uint32_t*, tLineOfSightResults*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))(Addresses::nProcessLineOfSight))(source, target, pUnk, pResults, nFlags, nUnk1, nUnk2, nUnk3, nUnk4);
	}
};