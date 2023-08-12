class CCheat
{
public:
	static inline auto& m_bHasPlayerCheated = AddressSetter::GetRef<bool>(0x11E3688, 0xF13B38);
};