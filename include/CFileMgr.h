class CFileMgr
{
public:
	static uint8_t* OpenFile(char* sPath, char* mode)
	{
		return ((uint8_t*(__cdecl*)(char*, char*))(AddressSetter::Get(0x3B2740, 0x456540)))(sPath, mode);
	}
	static void CloseFile(uint8_t* file)
	{
		((void(__cdecl*)(uint8_t*))(AddressSetter::Get(0x3B29E0, 0x4567E0)))(file);
	}
	// 2nd param usually 1
	static char* LoadLine(uint8_t* file, int unk)
	{
		return ((char*(__cdecl*)(uint8_t*, int))(AddressSetter::Get(0x3B2960, 0x456760)))(file, unk);
	}
};