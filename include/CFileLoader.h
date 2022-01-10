class CFileLoader
{
public:
	static inline char*& sAmbientDataPath = AddressSetter::GetRef<char*>(0x583720, 0x7E9F30); // common:/DATA/Ambient.dat

	// priority? it's set to 2 and 1 for loading default.dat in TBoGT but 0 everywhere else
	static void LoadLevel(char* levelName, int nUnk)
	{
		((void(__cdecl*)(char*, int))(AddressSetter::Get(0x4D79A0, 0x6CBE60)))(levelName, nUnk);
	}

	static void LoadObjectTypes(char* fileName)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x4D67E0, 0x6CACA0)))(fileName);
	}

	static void LoadWater(char* fileName)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x544920, 0x5AE4C0)))(fileName);
	}
};