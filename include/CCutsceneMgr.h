class CCutsceneMgr
{
public:
	static inline uint32_t& ms_running = *(uint32_t*)nullptr;

	bool IsRunning()
	{
		((bool(__cdecl*)())(Addresses::nCutsceneMgrIsRunning))();
	}
};