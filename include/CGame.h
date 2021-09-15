class CGame
{
public:
	static bool Initialise(const char* sGameDat)
	{
		return ((bool(__cdecl*)(const char*))(Addresses::nGameInitialise))(sGameDat);
	}
};