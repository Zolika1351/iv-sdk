class CGame
{
public:
	static uint32_t& m_nCurrentEpisode;
	static uint32_t& m_nCurrentEpisodeMenu; // mainly used for switching hudcolor in each episode's menu screen
	static bool Initialise(const char* sGameDat)
	{
		return ((bool(__cdecl*)(const char*))(Addresses::nGameInitialise))(sGameDat);
	}
};