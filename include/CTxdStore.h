class CTxdStore
{
	// txds are rage::pgDictionary<rage::grcTexture>
	// see 0x487460, loads fonts and buttons

	static int AddTxdSlot(char* sName)
	{
		return ((int(__cdecl*)(char*))(AddressSetter::Get(0x1EC20, 0x8EBC0)))(sName);
	}
	static void LoadTxd(int slot, char* sName)
	{
		((void(__cdecl*)(int, char*))(AddressSetter::Get(0x420D40, 0x4CCC60)))(slot, sName);
	}
	static void PushCurrentTxd()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x4204F0, 0x4CC410)))();
	}
	static void PopCurrentTxd()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x420960, 0x4CC880)))();
	}
};