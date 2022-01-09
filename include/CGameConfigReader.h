class CGameConfigReader
{
public:

	void LoadFile(char* fileName)
	{
		((void(__thiscall*)(CGameConfigReader*, char*))(AddressSetter::Get(0x4D5C10, 0x6CA0D0)))(this, fileName);
	}
};
CGameConfigReader*& GameConfigReader = AddressSetter::GetRef<CGameConfigReader*>(0x15AB8E0, 0x15CE578);