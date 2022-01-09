class CTimeCycle
{
public:
	static inline char*& sTimecycleModifierPath = AddressSetter::GetRef<char*>(0x48A651, 0x63AD31); // this is a push instruction but whatever x2

	static void Initialise()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x48AD70, 0x63B450)))();
	}
	static void InitModifiers()
	{
		return ((void(__cdecl*)())(AddressSetter::Get(0x48A650, 0x63AD30)))();
	}
};