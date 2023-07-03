class CFileLoader
{
public:
	static inline char*& sAmbientDataPath = AddressSetter::GetRef<char*>(0x583720, 0x7E9F30); // common:/DATA/Ambient.dat
	static inline char*& sGameRpfPath = AddressSetter::GetRef<char*>(0x866753, 0x7E1C83); // platform:/data/game.rpf
	static inline char*& sScenariosDatPath = AddressSetter::GetRef<char*>(0x4F8142, 0x7B17C2); // common:/DATA/Scenarios.dat
	static inline char*& sButtonsTxdPath = AddressSetter::GetRef<char*>(0x3FA992, 0x4876C2); // platform:/textures/buttons_360
	static inline char*& sProceduralDatPath = AddressSetter::GetRef<char*>(0x5081CD, 0x66E13D); // common:/data/materials
	static inline char*& sStreamIniPath = AddressSetter::GetRef<char*>(0x43290C, 0x4B489C); // platform:/stream.ini

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

	static void LoadSpeechData(char* fileName)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x8ECC70, 0x3A9620)))(fileName);
	}

	static void MountWavePack(char* fileName, char* mount)
	{
		((void(__cdecl*)(char*, char*))(AddressSetter::Get(0x8EB8D0, 0x38F8D0)))(fileName, mount);
	}

	static void LoadObject(char* pLine)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x4D2120, 0x6C6700)))(pLine);
	}

	static void LoadPedObject(char* pLine)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x4D11A0, 0x6C57E0)))(pLine);
	}

	static void LoadVehicleObject(char* pLine)
	{
		((void(__cdecl*)(char*))(AddressSetter::Get(0x4D5D70, 0x6CA230)))(pLine);
	}
};