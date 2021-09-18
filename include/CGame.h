class CGame
{
public:
	static inline uint32_t& m_nCurrentEpisode = *(uint32_t*)nullptr;
	static inline uint32_t& m_nCurrentEpisodeMenu = *(uint32_t*)nullptr; // mainly used for switching hudcolor in each episode's menu screen
	static bool Initialise(const char* sGameDat)
	{
		return ((bool(__cdecl*)(const char*))(Addresses::nGameInitialise))(sGameDat);
	}
};