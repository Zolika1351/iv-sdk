class CKeyGen
{
public:
	static uint32_t GetKey(char* sString, uint32_t* nExistingHash = nullptr)
	{
		return ((uint32_t(__cdecl*)(char*, uint32_t*))(Addresses::nGetKey))(sString, nExistingHash);
	}
};