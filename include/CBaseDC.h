class CBaseDC
{
public:
	uint8_t pad[0x8];					// 00-08
	static CBaseDC* Allocate(uint32_t nSize, uint32_t nUnk0)
	{
		return ((CBaseDC*(__cdecl*)(uint32_t, uint32_t))(AddressSetter::Get(0x3BDD80, 0x45E390)))(nSize, nUnk0);
	}
	void Add()
	{
		((void(__thiscall*)(CBaseDC*))(AddressSetter::Get(0x4E90, 0x75920)))(this);
	}
};
VALIDATE_SIZE(CBaseDC, 0x8);