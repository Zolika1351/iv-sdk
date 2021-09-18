class grcTexture
{
public:
	void SetTexture(char* sName)
	{
		((void(__thiscall*)(grcTexture*, char*))(AddressSetter::Get(0x4534A0, 0x45DF40)))(this, sName);
	}
};