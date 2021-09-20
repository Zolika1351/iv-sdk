class CTaskComplexMobileMakeCall : public CTaskComplex
{
public:
	void New(char* speechLine, bool bUnk_1, bool bUnk2)
	{
		((void(__thiscall*)(CTaskComplexMobileMakeCall*, char*, bool, bool))(AddressSetter::Get(0x4F5E00, 0x7AF830)))(this, speechLine, bUnk_1, bUnk2);
	}
};