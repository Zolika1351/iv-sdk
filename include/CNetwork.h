class CNetwork
{
public:
	static inline uint32_t& m_bNetworkSession = *(uint32_t*)nullptr;
	static inline uint32_t& m_nNetworkStatus = *(uint32_t*)nullptr;
	static bool IsNetworkGameRunning()
	{
		return ((bool(__cdecl*)())(Addresses::nIsNetworkGameRunning))();
	}
	static bool IsNetworkSession()
	{
		return ((bool(__cdecl*)())(Addresses::nIsNetworkSession))();
	}
};