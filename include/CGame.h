class CGame
{
public:
	static inline char*& sGameFile = AddressSetter::GetRef<char*>(0x1FDC9, 0x93949); // common:/data/gta.dat

	static inline uint32_t& m_nCurrentEpisode = AddressSetter::GetRef<uint32_t>(0xCF8044, 0xD2D754);
	static inline uint32_t& m_nCurrentEpisodeMenu = AddressSetter::GetRef<uint32_t>(0xCF8078, 0xD2D788); // used for switching hudcolor in each episode's menu screen and for loading the right episode when you hit play
	static bool Initialise(const char* sGameDat)
	{
		return ((bool(__cdecl*)(const char*))(AddressSetter::Get(0x4ADA50, 0x770660)))(sGameDat);
	}
};