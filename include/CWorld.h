class CEntity;

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
};