class CSprite2d
{
public:
	rage::grcTexture* m_pTexture;

	void SetTexture(char* sName)
	{
		((void(__thiscall*)(CSprite2d*, char*))(AddressSetter::Get(0x4534A0, 0x45DF40)))(this, sName);
	}
	void Delete()
	{
		((void(__thiscall*)(CSprite2d*))(AddressSetter::Get(0x4523E0, 0x45CE80)))(this);
	}
};
VALIDATE_SIZE(CSprite2d, 0x4);