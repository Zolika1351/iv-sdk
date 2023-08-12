class CWanted
{
public:
	static inline auto& MaximumWantedLevel = AddressSetter::GetRef<uint32_t>(0xB27A14, 0xB46074);
	static inline auto& nMaximumWantedLevel = AddressSetter::GetRef<uint32_t>(0xB27A18, 0xB46078);
};