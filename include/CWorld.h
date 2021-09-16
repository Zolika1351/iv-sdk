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
};