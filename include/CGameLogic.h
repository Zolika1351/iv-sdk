class CGameLogic
{
public:

	static void RestorePlayerStuffDuringResurrection(CPed* pPlayerPed, CVector NewCoors, float NewHeading)
	{
		((void(__cdecl*)(CPed*, CVector, float))(AddressSetter::Get(0x3B7B40, 0x3D46F0)))(pPlayerPed, NewCoors, NewHeading);
	}
};