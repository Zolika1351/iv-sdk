class CGameLogic
{
public:
	static inline auto& bPenaltyForDeathApplies = AddressSetter::GetRef<bool>(0xB0FCF8, 0xB2E150);
	static inline auto& bPenaltyForArrestApplies = AddressSetter::GetRef<bool>(0xB0FCF9, 0xB2E151);

	static bool Save()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x3B79F0, 0x3D45A0)))();
	}
	static bool Load()
	{
		return ((bool(__cdecl*)())(AddressSetter::Get(0x3B7A20, 0x3D45D0)))();
	}
	static void RestorePlayerStuffDuringResurrection(CPed* pPlayerPed, CVector NewCoors, float NewHeading)
	{
		((void(__cdecl*)(CPed*, CVector, float))(AddressSetter::Get(0x3B7B40, 0x3D46F0)))(pPlayerPed, NewCoors, NewHeading);
	}
};