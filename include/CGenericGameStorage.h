class CGenericGameStorage
{
public:
	static inline auto ms_ValidSaveName = (char*)AddressSetter::Get(0xDD66F0, 0xDD0380);

	// returns "SGTA4"
	static const char* GetDefaultPCSaveFileName()
	{
		return ((const char*(__cdecl*)())(AddressSetter::Get(0x42BE90, 0x457360)))();
	}
	static void MakeValidSaveName(const char* pString, int SlotNumber)
	{
		((void(__cdecl*)(const char*, int))(AddressSetter::Get(0x42C7B0, 0x457C70)))(pString, SlotNumber);
	}
	static bool SaveDataToWorkBuffer(void* pData, int32_t SizeOfData)
	{
		return ((bool(__cdecl*)(void*, int32_t))(AddressSetter::Get(0x42DEA0, 0x459360)))(pData, SizeOfData);
	}
	static bool LoadDataFromWorkBuffer(void* pData, int32_t SizeOfData)
	{
		return ((bool(__cdecl*)(void*, int32_t))(AddressSetter::Get(0x42DEB0, 0x459370)))(pData, SizeOfData);
	}
};