class CFileLoader
{
public:
	static void LoadLevel(char* levelName, int nUnk) // priority? it's set to 2 and 1 for loading default.dat in TBoGT but 0 everywhere else
	{
		((void(__cdecl*)(char*, int))(Addresses::nLoadLevel))(levelName, nUnk);
	}
};