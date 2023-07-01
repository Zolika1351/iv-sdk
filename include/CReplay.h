class CReplay
{
public:
	static inline auto& Mode = AddressSetter::GetRef<uint32_t>(0xCD0170, 0xD2EAC0);
};