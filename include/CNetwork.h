class CNetwork
{
public:
	static inline void*& m_pClientBroadcastVars = AddressSetter::GetRef<void*>(0x12C46FC, 0x127111C);
	static inline void*& m_pClientBroadcastVarSize = AddressSetter::GetRef<void*>(0x12C46EC, 0x127110C);
	static inline uint32_t& m_bNetworkSession = AddressSetter::GetRef<uint32_t>(0xCF806C, 0xD2D77C);
	static inline uint32_t& m_nNetworkStatus = AddressSetter::GetRef<uint32_t>(0x13E49B8, 0x1395524);
	static inline bool& m_bIsHostingGame = AddressSetter::GetRef<bool>(0x14A82FD, 0x14CB4EC);
	static bool IsNetworkGameRunning()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x62F90, 0x2C1A10)))();
	}
	static bool IsNetworkSession()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x3B79E0, 0x3D4590)))();
	}
	static void CheckFramerate(bool bUnk, int time)
	{
		((void(__cdecl*)(bool, int))(AddressSetter::Get(0x60310, 0x2BEDD0)))(bUnk, time);
	}
};