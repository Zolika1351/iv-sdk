class CTimeCycle
{
public:
	static void Initialise()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x48AD70, 0x63B450)))();
	}
	static void InitModifiers()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x48A650, 0x63AD30)))();
	}
};