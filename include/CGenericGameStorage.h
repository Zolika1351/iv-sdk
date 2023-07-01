class CGenericGameStorage
{
public:

	static bool SaveDataToWorkBuffer(void* pData, int32_t SizeOfData)
	{
		return ((bool(__cdecl*)(void*, int32_t))(AddressSetter::Get(0x42DEA0, 0x459360)))(pData, SizeOfData);
	}
	static bool LoadDataFromWorkBuffer(void* pData, int32_t SizeOfData)
	{
		return ((bool(__cdecl*)(void*, int32_t))(AddressSetter::Get(0x42DEB0, 0x459370)))(pData, SizeOfData);
	}
};