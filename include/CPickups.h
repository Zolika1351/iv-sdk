class CPickups
{
public:
	static void DoPickUpEffects()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x534280, 0x589100)))();
	}
};