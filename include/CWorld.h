class CWorld
{
public:
	static inline CPlayerInfo** Players; // Players[32]
	static inline int32_t& PlayerInFocus = *(int32_t*)nullptr;
};