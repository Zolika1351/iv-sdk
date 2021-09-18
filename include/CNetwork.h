class CNetwork
{
public:
	static inline uint32_t& m_bNetworkSession = AddressSetter::GetRef<uint32_t>(0xCF806C, 0xD2D77C);
	static inline uint32_t& m_nNetworkStatus = AddressSetter::GetRef<uint32_t>(0x13E49B8, 0x1395524);
	static bool IsNetworkGameRunning()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x62F90, 0x2C1A10)))();
	}
	static bool IsNetworkSession()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x3B79E0, 0x3D4590)))();
	}
};