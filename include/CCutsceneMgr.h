class CCutsceneMgr
{
public:
	static inline uint32_t& ms_running = *(uint32_t*)nullptr;

	static bool IsRunning()
	{
		return ((bool(__cdecl*)())(Addresses::nCutsceneMgrIsRunning))();
	}
};