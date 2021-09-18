class CTxdStore
{
public:
	// txds are rage::pgDictionary<rage::grcTexture>
	// see 0x487460, loads fonts and buttons

	static inline pgDictionary<grcTexture>*& ms_pStoredTxd = AddressSetter::GetRef<pgDictionary<grcTexture>*>(0x15ACACC, 0x15CE510);

	static int AddTxdSlot(char* sName)
	{
		return ((int(__cdecl*)(char*))(AddressSetter::Get(0x1EC20, 0x8EBC0)))(sName);
	}
	static int FindTxdSlot(uint32_t nHash)
	{
		return ((int(__cdecl*)(uint32_t))(AddressSetter::Get(0x1F130, 0x8F0B0)))(nHash);
	}
	static bool LoadTxd(int slot, char* sName)
	{
		return ((bool(__cdecl*)(int, char*))(AddressSetter::Get(0x420D40, 0x4CCC60)))(slot, sName);
	}
	static void PushCurrentTxd()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x4204F0, 0x4CC410)))();
	}
	static void SetCurrentTxd(int slot)
	{
		((void(__cdecl*)(int))(AddressSetter::Get(0x420900, 0x4CC820)))(slot);
	}
	static void PopCurrentTxd()
	{
		((void(__cdecl*)())(AddressSetter::Get(0x420960, 0x4CC880)))();
	}
};