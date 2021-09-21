void __declspec(naked) processScriptsEventHook()
{
	__asm
	{
		pushad
		call plugin::processScriptsEvent
		popad
		jmp Addresses::nProcessScriptsEventRet
	}
}
void __declspec(naked) gameLoadEventHook()
{
	__asm
	{
		pushad
		call plugin::gameLoadEvent
		popad
		jmp Addresses::nGameLoadEventRet
	}
}

namespace Overrides
{
	void GetTexture(CSprite2d(__stdcall* funcPtr)(char*))
	{
		injector::MakeJMP(AddressSetter::Get(0x21DA10, 0xD300), funcPtr);
	}
}