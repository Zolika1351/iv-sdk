// any non-class rage functions should go here
namespace rage
{
	static uint32_t atStringHash(char* sString, uint32_t* nExistingHash = nullptr)
	{
		return ((uint32_t(__cdecl*)(char*, uint32_t*))(AddressSetter::Get(0x1B1C30, 0x5CF50)))(sString, nExistingHash);
	}
}