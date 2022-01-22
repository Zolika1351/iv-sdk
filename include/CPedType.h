class CPedType
{
public:

	// takes pedtype string and returns 1 if PLAYER1, PLAYER2, PLAYER_NETWORK or PLAYER_UNUSED
	// if true the game sets CPedModelInfo::m_bStreamedPed to 1
	static bool IsPedTypePlayer(char* type)
	{
		return ((bool(__cdecl*)(char*))(AddressSetter::Get(0x7CB880, 0x806D60)))(type);
	}
	// returns pedtype id from string
	static int FindPedType(char* type)
	{
		return ((int(__cdecl*)(char*))(AddressSetter::Get(0x7CB8E0, 0x806DC0)))(type);
	}
};