class CStats
{
public:
	static inline auto LastMissionPassedName = (wchar_t*)AddressSetter::Get(0xDD61C0, 0xDCFE50);

	static void SetStatValue(uint16_t index, float NewValue)
	{
		((void(__cdecl*)(uint16_t, float))(AddressSetter::Get(0x563D00, 0x4D8330)))(index, NewValue);
	}
};