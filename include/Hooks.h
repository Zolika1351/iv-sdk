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