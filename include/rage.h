// any non-class rage functions should go here
namespace rage
{
	HWND& g_pHWND = AddressSetter::GetRef<HWND>(0x1449DDC, 0x1352060);
	IDirect3DDevice9*& g_pDirect3DDevice = AddressSetter::GetRef<IDirect3DDevice9*>(0x148AB48, 0x1345630);
	static uint32_t atStringHash(char* sString, uint32_t* nExistingHash = nullptr)
	{
		return ((uint32_t(__cdecl*)(char*, uint32_t*))(AddressSetter::Get(0x1B1C30, 0x5CF50)))(sString, nExistingHash);
	}
}