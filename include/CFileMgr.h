class CFileMgr
{
	static uint8_t* OpenFile(char* sPath, char* mode)
	{
		return ((uint8_t*(__cdecl*)(char*, char*))(AddressSetter::Get(0x3B2740, 0x456540)))(sPath, mode);
	}
	static void CloseFile(uint8_t* file)
	{
		((void(__cdecl*)(uint8_t*))(AddressSetter::Get(0x3B29E0, 0x4567E0)))(file);
	}
};